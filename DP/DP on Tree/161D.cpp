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
 
    int t = 1;
    while (t--)
    {
        int n, k; cin >> n >> k;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++) {
            int u,v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // d[u][i] : số lượng con thứ i của node u
        // dp[u][0] = 1
        // xét cạnh u-v với u là cha của v
        // dp[u][i] += dp[v][i-1]; 
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        int ans = 0;
        function<void(int, int)> dfs = [&](int u, int par){
            dp[u][0] = 1;
            for (auto v : adj[u]) {
                if (v == par) continue;
                dfs(v, u);
                for (int i = 0; i < k ; i++)
                    dp[u][i+1] += dp[v][i];
            }

            ans += dp[u][k];
            int tot = 0;
            for (auto v : adj[u]) {
                if (v == par) continue;
                for (int i = 1; i < k; i++) {
                    int j = k - i;
                    tot += dp[v][i-1]*(dp[u][j] - dp[v][j-1]);
                }
            }
            ans += tot/2;
        };
        dfs(0, -1);

        cout << ans << '\n';
    }
    return 0;
}