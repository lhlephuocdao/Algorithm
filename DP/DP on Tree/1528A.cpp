#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;
 
// directions: 0=up, 1=right, 2=down, 3=left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
 
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
 
    int t = 1; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++)
            cin >> l[i] >> r[i];
        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++) {
            int u,v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // dp[u][0] : maximum value of subtree at u if choosing l[u]
        // dp[u][1] : maximum value of subtree at u if choosing r[u]
        vector<vector<int>> dp(n, vector<int>(2, 0));
        function<void(int, int)> dfs = [&](int u, int par){
            for (auto v : adj[u]) {
                if (v == par) continue;
                dfs(v, u);

                int v0 = dp[v][0] + abs(l[u] - l[v]);
                int v1 = dp[v][1] + abs(l[u] - r[v]);
                dp[u][0] += max(v0, v1);

                v0 = dp[v][0] + abs(r[u] - l[v]);
                v1 = dp[v][1] + abs(r[u] - r[v]);
                dp[u][1] += max(v0, v1);
            }
        };
        dfs(0, -1);
        cout << max(dp[0][0], dp[0][1]) << '\n';
    }
    return 0;
}