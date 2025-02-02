#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << std::fixed;
    cout << std::setprecision(10);

    int n; cin >> n;
    double p[n+1];
    for (int i = 1; i <= n; i++) cin >> p[i];

    double dp[n+1][n+1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    dp[0][0] = 1.0;
    dp[0][1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = dp[i-1][j]*(1.0-p[i]) + ((j>0) ? dp[i-1][j-1]*p[i] : 0);
            // cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << '\n';
        }
    }

    double ans = 0;
    for (int j = (n/2)+1; j <= n; j++)
        ans += dp[n][j];

    cout << ans << '\n';

    return 0;
}