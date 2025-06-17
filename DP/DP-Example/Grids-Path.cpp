#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    const int mod = 1e9 + 7;

    int n; cin >> n;
    char a[n][n];
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < n; j++) a[i][j] = s[j];
    }

    vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
    dp[0][0] = (a[0][0] == '.') ? 1 : 0 ;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0) continue;
            if (i > 0 && a[i][j] == '.') dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            if (j > 0 && a[i][j] == '.') dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
        }

    cout << dp[n-1][n-1] << '\n';

    return 0;
}