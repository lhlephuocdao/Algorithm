#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int INF = 1e18;

// directions: 0=up, 1=right, 2=down, 3=left
// 4=up-left, 5=down-right, 6=up-right, 7=down-left
int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug :
 *      - duplicated element
 *      - consecutive range: 1 2 3 4 5 ....
 * stress test
 */

int32_t main()
{
    fastio;

    const int maxv = 1e7;
    vector<bool> is_prime(maxv+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= maxv; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxv; j += i)
            is_prime[j] = false;
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= maxv; i++)
        if (is_prime[i]) primes.push_back(i);

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n,m; cin >> n >> m;
        vector<int> v(n);
        for (auto& x : v) cin >> x;

        /*
            dp[k][s] : min winner score to distribute subset s to k player
            dp[k][s] = max(dp[k-1][s ^ i], dp[1][i])
            dp[1][i] : score to distribute subset i to 1 player
        */

        function<int(int)> closest = [&](int sum) {
            if (sum == 1) return 2ll;
            if (sum == 2) return 3ll;
            if (sum == 3) return 2ll;
            auto itr = lower_bound(primes.begin(), primes.end(), sum);
            if (*itr != sum) {
                int val1 = *itr;
                itr--;
                int val2 = *itr;
                int res1 = abs(val1-sum);
                int res2 = abs(val2-sum);
                if (res1 < res2) return val1;
                else return val2;
            } else {
                // sum is prime
                auto itr2 = itr;
                itr2++;
                int val2 = *itr2;
                itr--;
                int val1 = *itr;
                int res1 = abs(val1-sum);
                int res2 = abs(val2-sum);
                if (res1 < res2) return val1;
                else return val2;
            }
        };

        vector<vector<int>> dp(m+1, vector<int>(1<<n, INF));
        for (int i = 1; i < (1<<n); i++) {
            int total = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    total += v[j];
                }
            }

            dp[1][i] = abs(closest(total) - total);
        }

        for (int s = 2; s < (1<<n); s++) {
            for (int k = 2; k <= m; k++) {
                // Need to iterate over all subsets of bitmask s
                for (int i = s; i > 0; i = (i-1)&s) {
                    // i : subset of bitmask s
                    dp[k][s] = min(dp[k][s], max(dp[k-1][s^i], dp[1][i]));
                }
            }
        }

        cout << dp[m][(1<<n)-1] << '\n';
    }

    return 0;
}