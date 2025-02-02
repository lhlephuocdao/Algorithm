#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n;
vector<int> prime, expo(16, -1);
ll ans = 0;

void init()
{
    vector<bool> is_prime(60, true);
    for (int i = 2; i <= 55; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            int j = 2*i;
            while (j <= 55) {
                is_prime[j] = false;
                j += i;
            }
        }
    }
}

void backtrack(int pos, ll cur)
{
    if (pos == 16)
    {
        // cout << "end cur: " << cur << '\n';
        long long tmp = 1;
        for (auto x : expo) {
            // cout << x << " ";
            tmp *= (x+1);
        }
        ans = max(ans, tmp);
        // cout << "\nans: " << ans << '\n';
        return;
    }

    ll tmp = 1;
    // cout << "pos: " << pos << " cur: " << cur << '\n';
    for (int i = 0; i < 60; i++)
    {
        if (i > 0)  tmp *= prime[pos];
        // cout << "tmp: " << tmp << '\n';
        if (tmp > n) return;

        if ((tmp>1 && (LONG_LONG_MAX/tmp + 1) < cur) || (cur*tmp > n)) return;
        
        cur *= tmp;
        expo[pos] = i;
        backtrack(pos+1, cur);
        expo[pos] = -1;
        cur /= tmp;
    }
}

void solve()
{
    cin >> n;
    backtrack(0, 1);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    int t; cin >> t;
    while (t--) solve();

    return 0;
}