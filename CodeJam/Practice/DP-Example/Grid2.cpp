#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W, N;
    cin >> H >> W >> N;

    ll dp[H+1][W+1];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;

    int a[H+1][W+1];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= N; i++)
    {
        int r, c;
        cin >> r >> c;
        a[r][c] = 1;
    }
    

    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
        {
            if (i==1 && j==1) continue;
            if (a[i][j] == 0) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                dp[i][j] %= mod;
            }
        }

    cout << dp[H][W] << '\n';

    return 0;
}