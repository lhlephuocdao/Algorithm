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
 
struct LCA {
    int root;
    int log;
    vector<int> h;
    vector<vector<int>> up;
    vector<vector<int>> max_w;
    vector<vector<int>> min_w;
 
    LCA(vector<vector<pii>>& g, int r) {
        root = r;
        int n = g.size();
        log = __lg(n);
        h.assign(n, 0);
        up.assign(n, vector<int>(log+1));
        max_w.assign(n, vector<int>(log+1));
        min_w.assign(n, vector<int>(log+1));
        dfs(root, g);
    }
 
    void dfs(int u, vector<vector<pii>>& g) {
        for (auto p : g[u]) {
            int v = p.first;
            int w = p.second;
            if (v == up[u][0]) continue;
            h[v] = h[u] + 1;
     
            up[v][0] = u; // parent of v is u
            max_w[v][0] = w; // max_w from v -> u : w
            min_w[v][0] = w; // min_w from v -> u : w
            for (int j = 1; j <= log; ++j) {
                up[v][j] = up[up[v][j - 1]][j - 1];

                max_w[v][j] = max(max_w[v][j-1], max_w[up[v][j-1]][j-1]);
                min_w[v][j] = min(min_w[v][j-1], min_w[up[v][j-1]][j-1]);
            }
     
            dfs(v, g);
        }
    }
 
    int lca(int u, int v) {
        if (h[u] != h[v]) {
            if (h[u] < h[v]) swap(u, v);
     
            int k = h[u] - h[v];
            for (int j = 0; (1 << j) <= k; ++j)
                if (k >> j & 1)
                    u = up[u][j];
        }
        if (u == v) return u;
     
        int k = __lg(h[u]);
        for (int j = k; j >= 0; --j)
            if (up[u][j] != up[v][j])
                u = up[u][j], v = up[v][j];
        return up[u][0];
    }
 
    pii get(int u, int v) {
        int maxw = INT_MIN, minw = INT_MAX;
        if (h[u] != h[v]) {
            if (h[u] < h[v]) swap(u, v);
             
            int k = h[u] - h[v];
            for (int j = 0; (1 << j) <= k; ++j)
                if (k >> j & 1) {
                    maxw = max(maxw, max_w[u][j]);
                    minw = min(minw, min_w[u][j]);
                    u = up[u][j];
                }
        }
        if (u == v) return {minw, maxw};
     
        int k = __lg(h[u]);
        for (int j = k; j >= 0; --j)
            if (up[u][j] != up[v][j]) {
                maxw = max(maxw, max(max_w[u][j], max_w[v][j]));
                minw = min(minw, min(min_w[u][j], min_w[v][j]));
                u = up[u][j], v = up[v][j];
            }

        maxw = max(maxw, max(max_w[u][0], max_w[v][0]));
        minw = min(minw, min(min_w[u][0], min_w[v][0]));
        return {minw, maxw};
    }
};
 
int32_t main()
{
    fastio;
 
    int t = 1;
    while (t--)
    {
        int n; cin >> n;
        vector<vector<pii>> adj(n);
        for (int i = 0; i < n-1; i++) {
            int u,v,w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        LCA lca(adj, 0);

        int k; cin >> k;
        while (k--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            auto ans = lca.get(u, v);
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }
    return 0;
}