#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
int n, maxw;
int w[maxn];
pair<int, int> dp[1<<maxn];

int solve1()
{
    // ios_base::sync_with_stdio();
    // cin.tie(0); cout.tie(0);

    // cin >> n >> maxw;
    // for (int i = 0; i < n; i++) cin >> w[i];

    for (int i = 0; i < (1<<n); i++) {
        dp[i].first = INT_MAX;
        dp[i].second = 0;
    }
    dp[0].first = 1;
    dp[0].second = maxw;

    for (int i = 0; i < (1<<n); i++) // i : subset of people is already in the elevator
    {
        // cout << "i : " << i << '\n';
        for (int x = 0; x < n; x++)
        {
            // cout << "x : " << x << '\n';
            if (i & (1<<x)) continue; 

            int m = dp[i].second;
            if (w[x] <= m) {
                dp[i | (1<<x)].first = min(dp[i | (1<<x)].first, dp[i].first);
                dp[i | (1<<x)].second = max(dp[i | (1<<x)].second, m-w[x]);
            } else {
                dp[i | (1<<x)].first = min(dp[i | (1<<x)].first, dp[i].first + 1);
                dp[i | (1<<x)].second = max(dp[i | (1<<x)].second, max(m, maxw-w[x]));
            }

            // cout << "dp[" << (i | (1<<x)) << "].first : " << dp[i | (1<<x)].first << '\n';
            // cout << "m : ";
            // for (auto a : m) cout << a << " ";
            // cout << '\n';
        }
    }

    // cout << dp[(1<<n) - 1].first << '\n';

    return dp[(1<<n) - 1].first;
}

// ====================================

pair<int, multiset<int>> f[1<<maxn];
int refer_code()
{
    for (int i = 0; i < (1<<n); i++) {
        f[i].first = INT_MAX;
        f[i].second.clear();
    }
    f[0].first = 0;

    for (int i = 0; i < (1<<n); i++) // i : subset of people is already in the elevator
    {
        // cout << "i : " << i << '\n';
        for (int x = 0; x < n; x++)
        {
            // cout << "x : " << x << '\n';
            if (i & (1<<x)) continue; 

            multiset<int> m = f[i].second;
            auto itr = m.lower_bound(w[x]);
            if (m.empty() || itr == m.end()) {
                if ((f[i].first + 1) < f[i | (1<<x)].first) {
                    m.insert(maxw - w[x]);
                    f[i | (1<<x)].first = f[i].first + 1;
                    f[i | (1<<x)].second = m;
                }
            } else {
                if (f[i].first < f[i | (1<<x)].first) {
                    int t = *itr;
                    m.erase(m.find(t));
                    m.insert(t - w[x]);
                    f[i | (1<<x)].first = f[i].first;
                    f[i | (1<<x)].second = m;
                }
            }

            // cout << "f[" << (i | (1<<x)) << "].first : " << f[i | (1<<x)].first << '\n';
            // cout << "m : ";
            // for (auto a : m) cout << a << " ";
            // cout << '\n';
        }
    }

    return f[(1<<n) - 1].first;
}

// ====================================

void show()
{
    for (int i = 0; i < n; i++)
        cout << w[i] << " ";
    cout << '\n';
}

long long generate_random_int(long long min, long long max) {
    return min + (rand() % (long long)(max - min + 1));
}

void stress_test(long long size, long long min, long long max) {
    int idx = 1;
    while(1) {
        cout << "Iteration: " << idx << "\n";
        n = generate_random_int(1, 5);
        maxw = generate_random_int(1, 10);
        // cout << n << " " << maxw << '\n';
        memset(w, 0, sizeof(w));

        for(int i = 0; i < n; ++i) {
            w[i] = generate_random_int(1, maxw);
            // cout << w[i] << " ";
        }
        // cout << '\n';

        int my_ans = solve1();
        // cout << "solve1: " << my_ans << '\n'; 
        int refer_ans = refer_code();
        // cout << "solve2: " << refer_ans << '\n'; 
        if(my_ans != refer_ans) {
            cout << "Fail: failed not less case\n";
            cout << "n = " << n << " maxw: " << maxw << '\n';
            show();
            cout << "Expected: " << refer_ans << "\n";
            cout << "ACTUAL: " << my_ans << "\n";
            break;
        }
        cout << "PASS\n";
        ++idx;
    }
}

signed main() {
    srand(time(0));
    stress_test(100000, 1, 10000000000000);
    return 0;
}