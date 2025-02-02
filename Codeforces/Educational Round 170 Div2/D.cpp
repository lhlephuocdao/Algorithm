#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> r(n+1, 0);
    vector<int> pos[m+1], neg[m+1];
    int zero = 0;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        if (r[i] > 0) pos[zero].push_back(r[i]);
        else if (r[i] < 0) neg[zero].push_back(-r[i]);
        else zero++;
    }

    for (int i = 0; i <= m; i++) {
        sort(pos[i].begin(), pos[i].end());
        sort(neg[i].begin(), neg[i].end());
    }

    vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
    /*
        dp[i][j] : number of rounds we can win
                    if we are in i-th 0,
                    and we have already j intelligence points
        i <= m, j < i;

        if take i-th 0 as Intelligence point -> we have j+1 Intelligence points and i-j-1 Strength points
            +) dp[i][j+1] = dp[i-1][j] + wins
                wins : number of checks (on both Intelligence and Strength checks) 
                        we can pass from (i)-th 0 -> (i+1)-th 0    

        if we take i-th 0 as Strength points -> we have j Intelligence points and i-j Strength points
            +) dp[i][j]= dp[i-1][j] + wins
    */

    int i = 0;
    // pos : intelligence checks
    // neg : strength checks
    for (int k = 0; k < n; k++)
    {
        if (r[k] == 0) {
            i++;
            for (int j = 0; j < i; j++)
            {
                // if take i-th 0 as Intelligence point
                int inte = j+1, stre = i-j-1;
                int wins = upper_bound(pos[i].begin(), pos[i].end(), inte) - pos[i].begin()
                         + upper_bound(neg[i].begin(), neg[i].end(), stre) - neg[i].begin();
                dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + wins);

                // if we take i-th 0 as Strength points
                inte = j;
                stre = i-j;
                wins = upper_bound(pos[i].begin(), pos[i].end(), inte) - pos[i].begin()
                         + upper_bound(neg[i].begin(), neg[i].end(), stre) - neg[i].begin();
                dp[i][j] = max(dp[i][j], dp[i-1][j] + wins);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= m; j++)
        ans = max(ans, dp[m][j]);

    cout << ans << '\n';

    return 0;
}