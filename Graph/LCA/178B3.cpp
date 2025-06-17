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
 
struct DSU {
    vector<int> parent, rank;
 
    DSU(int n) : parent(n), rank(n) {};
 
    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }
 
    int find_set(int v) {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }
 
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a,b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};
 
struct edge {
    int idx, w, u, v;
    bool operator<(edge const& other) {
        return w < other.w;
    }
};
 
struct LCA {
    int root;
    int log;
    vector<int> h;
    vector<vector<int>> up, cnt;
    map<int, set<int>> bridges;
 
    LCA(vector<vector<int>>& g, int r, map<int, set<int>>& b) {
        root = r;
        int n = g.size();
        log = __lg(n);
        h.assign(n, 0);
        up.assign(n, vector<int>(log+1));
        cnt.assign(n, vector<int>(log+1, 0));
        bridges = b;
        dfs(root, g);
    }
 
    void dfs(int u, vector<vector<int>>& g) {
        for (auto v : g[u]) {
            if (v == up[u][0]) continue; // if v is parent of u -> continue
            h[v] = h[u] + 1;
     
            up[v][0] = u; // parent of v is u
            if (bridges[u].find(v) != bridges[u].end()) // u-v is a bridge
            {
                cnt[v][0] = 1;
                // cout << "cnt[" << v << "][0] = 1\n";
            }

            for (int j = 1; j <= log; ++j) {
                up[v][j] = up[up[v][j-1]][j-1];
                cnt[v][j] += cnt[v][j-1] + cnt[up[v][j-1]][j-1];
                // cout << "cnt[" << v << "][" << j << "] = " << cnt[v][j] << '\n';
            }
     
            dfs(v, g);
        }
    }
 
    int count_bridges(int u, int v) {
        int ans = 0;
        if (h[u] != h[v]) {
            if (h[u] < h[v]) swap(u, v);
     
            int k = h[u] - h[v];
            for (int j = 0; (1 << j) <= k; ++j)
                if (k >> j & 1) {
                    ans += cnt[u][j];
                    u = up[u][j];
                }
        }
        if (u == v) return ans;
     
        int k = __lg(h[u]);
        for (int j = k; j >= 0; --j)
            if (up[u][j] != up[v][j]) {
                ans += cnt[u][j];
                ans += cnt[v][j];
                u = up[u][j], v = up[v][j];
            }

        ans += cnt[u][0];
        ans += cnt[v][0];
        
        return ans;
    }
};
 
int32_t main()
{
    fastio;
 
    int t = 1;
    while (t--)
    {
        int n, m; cin >> n >> m;
        vector<edge> E(m);
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int x,y, w = 1;
            cin >> x >> y;
            x--, y--;
            E[i] = {i, w, x, y};
            g[x].push_back(y);
            g[y].push_back(x);
        }
 
        // 1. Find MST of graph
        DSU dsu(n);
        for (int i = 0; i < n; i++) dsu.make_set(i);
        sort(E.begin(), E.end());
 
        vector<edge> mst;
        for (edge e : E) {
            int f_u = dsu.find_set(e.u);
            int f_v = dsu.find_set(e.v);
            if (dsu.find_set(e.u) != dsu.find_set(e.v)) {
                mst.push_back(e);
                dsu.union_sets(e.u, e.v);
            }
        }

        // cout << "MST: \n";
        // for (edge e : mst) cout << e.u << ' ' << e.v << '\n';
 
        // 2. Find all briges
        vector<bool> visited(n, false);
        vector<int> tin(n, -1), low(n, -1);
        int timer = 0;
        map<int, set<int>> bridges;
        function<void(int, int)> dfs = [&](int v, int p) {
            visited[v] = true;
            tin[v] = low[v] = timer++;
            bool parent_skipped = false;
            for (int to : g[v]) {
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

        // cout << "all bridges:\n";
        // for (auto it : bridges) {
        //     cout << it.first << " : ";
        //     for (auto x : it.second) cout << x << ' ';
        //     cout << '\n';
        // }

        // 3. Build LCA
        vector<vector<int>> adj(n);
        for (edge e : mst) {
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);
        }
        int root = 0;
        LCA lca(adj, root, bridges);

        int k; cin >> k;
        while (k--) {
            int s,l;
            cin >> s >> l;
            s--, l--;
            cout << lca.count_bridges(s, l) << '\n';
        }
        
    }
    return 0;
}