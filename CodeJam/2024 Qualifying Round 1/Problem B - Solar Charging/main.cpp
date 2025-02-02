#include <bits/stdc++.h>

using namespace std;

// #define big __int64
#define MAX 9223372036854775807
#define ll long long

const int maxN = 1000 + 7;


void solve()
{
    int N,C,B, P[maxN], F[maxN], D[maxN];
    cin >> N >> B >> C;
    for (int i = 0; i < N; i++)
        cin >> P[i];
    for (int i = 0; i < N; i++)
        cin >> F[i];
    for (int i = 0; i < N; i++)
        cin >> D[i];

    vector<vector<ll>> dp(N+1, vector<ll>(C+1, MAX));
    // dp[i][j] represents the minimum cost to reach day i with battery charge j
    dp[0][B] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= C; j++) {
            if (dp[i-1][j] != MAX) {
                // i = 5, j = 1
                //Use battery
                int newCharge = max(0, j-D[i-1]);
                // cout << "j-D[i-1]: " << j-D[i-1] << '\n';
                if (j-D[i-1] >= 0) dp[i][newCharge] = min(dp[i][newCharge], dp[i-1][j]);
                // cout << "newCharge: dp[" << i << "][" << newCharge << "] = " << dp[i][newCharge] << '\n';

                //Charge battery
                int maxCharge = min(C, j + P[i-1]);
                dp[i][maxCharge] = min(dp[i][maxCharge], dp[i-1][j] + (ll)F[i-1]*D[i-1]);
                // cout << "maxCharge: dp[" << i << "][" << maxCharge << "] = " << dp[i][maxCharge] << '\n';
            }
        }
    }

    //Finding minimum cost
    ll minCost = MAX;
    for (int j = B; j <= C; j++)
        minCost = min(minCost, dp[N][j]);

    cout << minCost << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}