#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string a,b,c;
    cin >> a >> b >> c;
    int n = a.length(), m = b.length();
    a = " " + a;
    b = " " + b;
    c = " " + c;

    /*
        dp[i][j] : min number of characters
                that could have been changed by getting the first i-th characters of a
                and getting the first j-th characters of b

        dp[0][0] = 0
        dp[i][j] = min(dp[i][j], dp[i-1][j] + 1 if a[i] != c[i+j], dp[i][j-1] + 1 if b[j] != c[i+j])
    */

   vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
   dp[0][0] = 0;

   for (int i = 0; i <= n; i++)
   {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0) continue;

            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + ((b[j] != c[i+j]) ? 1 : 0));
            }

            if (i>0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + ((a[i] != c[i+j]) ? 1 : 0));
            }
        }
   }

   cout << dp[n][m] << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}