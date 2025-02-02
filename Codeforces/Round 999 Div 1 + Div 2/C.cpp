#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 998244353;

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug
 * stress test
 */

int32_t main()
{
    fastio;

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = (a[0] == 0) ? 1 : 0;
        dp[0][1] = 1;

        for (int i = 1; i < n; i++)
        {
            // i-th noi that
            // i-1 th noi that
            if (a[i] == a[i-1]) {
                dp[i][0] += dp[i-1][0];
                dp[i][0] %= mod;
            }

            // i-1 noi doi => i-2 noi that
            if ((i>=2 && a[i] == a[i-2] + 1) || (i == 1 && a[i] == 1)) {
                dp[i][0] += dp[i-1][1];
                dp[i][0] %= mod;
            }

            // i-th noi doi => i-1 noi that
            dp[i][1] = dp[i-1][0];
            dp[i][1] %= mod;

            // cout << "i: " << i << " " << dp[i][0] << " " << dp[i][1] << '\n';
        }

        cout << (dp[n-1][0] + dp[n-1][1])%mod << '\n';
    }
    return 0;
}