#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W;
    cin >> H >> W;

    ll dp[H+1][W+1];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;

    char a[H+1][W+1];
    for (int i = 1; i <= H; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < W; j++)
            a[i][j+1] = s[j];
    }
    

    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
        {
            if (i==1 && j==1) continue;
            if (a[i][j] == '.') {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                dp[i][j] %= mod;
            }
        }

    cout << dp[H][W] << '\n';

    return 0;
}