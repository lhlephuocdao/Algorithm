#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;
const int INF = 1e18;

// directions: 0=up, 1=right, 2=down, 3=left
// 4=up-left, 5=down-right, 6=up-right, 7=down-left
int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug :
 *      - duplicated element
 *      - consecutive range: 1 2 3 4 5 ....
 * stress test
 */

int32_t main()
{
    fastio;

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        // D[k][i][j] : time to go from city i to city j using method k
        vector<vector<vector<int>>> D(n, vector<vector<int>>(n, vector<int>(n)));
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    cin >> D[k][i][j];

        /*
            Start from city 0, visit all cities from 1 to n-1 exactly once and return to city 0
            Each method is used exactly once
        */

        // dp[1<<n][n][1<<n]
        // dp[m][i][s] : min time to reach city i, visited all cities in subset s
        //              , and used all methods in subset m
        // dp[0][0][1] = 0 : NO take time to reach city 0, and used no method
        vector<vector<vector<int>>> dp(1<<n, vector<vector<int>>(n+1, vector<int>(1<<n, INF)));
        vector<vector<vector<int>>> dp2(1<<n, vector<vector<int>>(n+1, vector<int>(1<<n, -INF)));
        // dp : min, dp2 : max
        dp[0][0][1<<0] = 0;
        dp2[0][0][1<<0] = 0;

        for (int s = 1; s < (1 << n); s++) {
            // s : subset of cities that visit
            for (int i = 0; i < n; i++) {
                if (!(s & (1<<i))) continue; // Nếu city i không nằm trong tập s -> continue

                // dp[i][s] = dp[]
                for (int m = 0; m < (1<<n); m++) {
                    // m : subset of methods that used
                    int cur = dp[m][i][s]; // min time để đến city i và đã thăm all cities in subset s and used all methods in subset m
                    int cur2 = dp2[m][i][s];
                    if (cur == INF) continue;
                    for (int j = 0; j < n; j++) {
                        if (m & (1<<j)) continue; // method j đã được sử dụng
                        for (int to = 0; to < n; to++) {
                            if (s & (1<<to)) continue; // city to đã được thăm
                            if (D[j][i][to] == 0) continue; // không có đường đi từ city i to city 'to' using method j

                            int next_m = m | (1<<j);
                            int next_s = s | (1<<to);
                            dp[next_m][to][next_s] = min(dp[next_m][to][next_s], cur + D[j][i][to]);
                            dp2[next_m][to][next_s] = max(dp2[next_m][to][next_s], cur2 + D[j][i][to]);
                        }
                    }
                }
            }
        }

        int ans_min = INF, ans_max = -INF;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // come back from city i to city 0 using method j
                // method j chưa được sử dụng trước đó
                // => methodFlag = ((1<<n)-1) & ~(1<<j)
                if (D[j][i][0] == 0) continue;
                int methodFlag = ((1<<n)-1) & ~(1<<j);
                int cur = dp[methodFlag][i][(1<<n)-1];
                int cur2 = dp2[methodFlag][i][(1<<n)-1];
                ans_min = min(ans_min, cur + D[j][i][0]);
                ans_max = max(ans_max, cur2 + D[j][i][0]);
            }
        }

        if (ans_min == INF)
            cout << "0 0\n";
        else
            cout << ans_min << ' ' << ans_max << '\n';
    }

    return 0;
}
