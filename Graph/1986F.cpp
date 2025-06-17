#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

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
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u,v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        vector<int> tin(n, -1), low(n, -1);
        int timer = 0;
        map<int, set<int>> bridges;
        function<void(int, int)> dfs = [&](int v, int p) {
            visited[v] = true;
            tin[v] = low[v] = timer++;
            bool parent_skipped = false;
            for (int to : adj[v]) {
                if (to == p && !parent_skipped) {
                    parent_skipped = true;
                    continue;
                }
                if (visited[to]) {
                    low[v] = min(low[v], tin[to]);
                } else {
                    dfs(to, v);
                    low[v] = min(low[v], low[to]);
                    if (low[to] > tin[v]) {
                        bridges[v].insert(to);
                        bridges[to].insert(v);
                    }
                }
            }
        };
        dfs(0, -1);

        visited.assign(n, false);
        vector<int> sz(n, 0);
        function<void(int, int)> dfs2 = [&](int u, int prev) {
            visited[u] = true;
            for (int v : adj[u]) {
                if (v == prev || visited[v]) continue;
                dfs2(v, u);
                sz[u] += sz[v];
            }

            sz[u] += 1;
        };
        dfs2(0, -1);

        int ans = n*(n-1)/2;
        visited.assign(n, false);
        function<void(int, int)> dfs3 = [&](int u, int prev){
            visited[u] = true;
            for (int v : adj[u]) {
                if (v == prev || visited[v]) continue;

                if (bridges[u].find(v) != bridges[u].end()) {
                    int s1 = sz[v];
                    int s2 = sz[0] - sz[v];
                    int ret = s1*(s1-1)/2 + s2*(s2-1)/2;
                    ans = min(ans, ret);
                }

                dfs3(v, u);
            }
        };
        dfs3(0, -1);

        cout << ans << '\n';
    }

    return 0;
}