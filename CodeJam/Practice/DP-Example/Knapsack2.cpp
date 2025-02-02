#include <bits/stdc++.h>

using namespace std;

const int maxv = 50 + 7;
const int maxw = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, W;
    cin >> N >> W;

    int w[110], v[110];
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

    /*
        F[i][j] : minimum weights that choosing some of the first i items
                  and has sum values is  j
        F[i+1][j] = F[i][j]
        F[i+1][j + v[i+1]] = F[i][j] + w[i+1]
    */

    vector<vector<long long>> dp(110, vector<long long>(maxv, INT_MAX));

    for (int j = 1; j < maxv; j++)
        if (j <= v[0]) dp[0][j] = w[0];
        
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 1; j < maxv; j++)
        {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            cout << "dp[" << i+1 << "][" << j << "]: " << dp[i+1][j] << '\n';
            if (j + v[i+1] < maxv) {
                dp[i+1][j+v[i+1]] = min(dp[i+1][j+v[i+1]], dp[i][j] + w[i+1]);
                cout << "dp[" << i+1 << "][" << j+v[i+1] << "]: " << dp[i+1][j+v[i+1]] << '\n';
            }
        }
    }

    for (int j = maxv-1; j >= 1; j--)
    {
        if (dp[N-1][j] <= W) {
            cout << j << '\n';
            break;
        }
    }

    return 0;
}