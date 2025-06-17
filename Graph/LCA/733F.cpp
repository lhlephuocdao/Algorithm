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
    int idx, w, c, u, v;
    bool operator<(edge const& other) {
        return w < other.w;
    }
};
 
struct LCA {
    int root;
    int log;
    vector<int> h;
    vector<vector<int>> up;
    vector<vector<int>> max_w;
    vector<vector<int>> max_id;
 
    LCA(vector<vector<pair<int, pii>>>& g, int r) {
        root = r;
        int n = g.size();
        log = __lg(n);
        h.assign(n, 0);
        up.assign(n, vector<int>(log+1));
        max_w.assign(n, vector<int>(log+1));
        max_id.assign(n, vector<int>(log+1));
        dfs(root, g);
    }
 
    void dfs(int u, vector<vector<pair<int, pii>>>& g) {
        for (auto p : g[u]) {
            int v = p.first;
            int w = p.second.first;
            int id = p.second.second;
            if (v == up[u][0]) continue;
            h[v] = h[u] + 1;
     
            up[v][0] = u; // parent of v is u
            max_w[v][0] = w; // max_w from v -> u : w
            max_id[v][0] = id; // id of the max_w edge from u->v
            for (int j = 1; j <= log; ++j) {
                up[v][j] = up[up[v][j - 1]][j - 1];
 
                if (max_w[v][j-1] > max_w[up[v][j-1]][j-1]) {
                    max_w[v][j] = max_w[v][j-1];
                    max_id[v][j] = max_id[v][j-1];
                } else {
                    max_w[v][j] = max_w[up[v][j-1]][j-1];
                    max_id[v][j] = max_id[up[v][j-1]][j-1];
                }
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
 
    pii get_max_w(int u, int v) {
        int ans = LLONG_MIN;
        int idx = -1;
        if (h[u] != h[v]) {
            if (h[u] < h[v]) swap(u, v);
             
            int k = h[u] - h[v];
            for (int j = 0; (1 << j) <= k; ++j)
                if (k >> j & 1) {
                    if (ans < max_w[u][j]) {
                        ans = max_w[u][j];
                        idx = max_id[u][j];
                    }
                    u = up[u][j];
                }
        }
        if (u == v) return {ans, idx};
     
        int k = __lg(h[u]);
        for (int j = k; j >= 0; --j)
            if (up[u][j] != up[v][j]) {
                if (ans < max_w[u][j]) {
                    ans = max_w[u][j];
                    idx = max_id[u][j];
                }
                if (ans < max_w[v][j]) {
                    ans = max_w[v][j];
                    idx = max_id[v][j];
                }
                u = up[u][j], v = up[v][j];
            }
 
        if (ans < max_w[u][0]) {
            ans = max_w[u][0];
            idx = max_id[u][0];
        }
        if (ans < max_w[v][0]) {
            ans = max_w[v][0];
            idx = max_id[v][0];
        }
        return {ans, idx};
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
        for (int i = 0; i < m; i++) {
            int w; cin >> w;
            E[i].idx = i;
            E[i].w = w;
        }
 
        for (int i = 0; i < m; i++)
            cin >> E[i].c;
        for (int i = 0; i < m; i++) {
            int x,y;
            cin >> x >> y;
            x--, y--;
            E[i].u = x;
            E[i].v = y;
        }
 
        int S; cin >> S;
 
        // 1. Find MST of graph
        DSU dsu(n);
        for (int i = 0; i < n; i++) dsu.make_set(i);
        sort(E.begin(), E.end());
 
        vector<edge> mst, non_mst;
        int sum = 0;
        for (edge e : E) {
            int f_u = dsu.find_set(e.u);
            int f_v = dsu.find_set(e.v);
            if (dsu.find_set(e.u) != dsu.find_set(e.v)) {
                sum += e.w;
                mst.push_back(e);
                dsu.union_sets(e.u, e.v);
            } else {
                non_mst.push_back(e);
            }
        }
 
        // 2. Build LCA
        vector<vector<pair<int, pii>>> adj(n);
        for (edge e : mst) {
            adj[e.u].push_back({e.v, {e.w, e.idx}});
            adj[e.v].push_back({e.u, {e.w, e.idx}});
        }
        int root = 0;
        LCA lca(adj, root);
 
        // 3. Handle case edges of MST
        int best_sum = sum;
        int best_id = -1;
        for (edge e : mst) {
            int c = e.c;
            if (best_sum > sum - S/c) {
                best_sum = sum - S/c;
                best_id = e.idx;
            }
        }
 
        // 4. Handle case edges of non-MST
        int remove_id = -1;
        for (edge e : non_mst) {
            int w = e.w;
            int c = e.c;
            auto p = lca.get_max_w(e.u, e.v);
            int max_w = p.first;
            int n_sum = sum - max_w + w - S/c;
            if (best_sum > n_sum) {
                best_sum = n_sum;
                best_id = e.idx;
                remove_id = p.second;
            }
        }
 
        cout << best_sum << '\n';
        for (edge e : mst) {
            if (e.idx != remove_id) {
                int w = e.w;
                if (e.idx == best_id) w -= S/e.c;
                cout << e.idx+1 << ' ' << w << '\n';
            }
        }
 
        if (remove_id != -1) {
            for (edge e : non_mst) {
                if (e.idx == best_id) {
                    int w = e.w - S/e.c;
                    cout << best_id+1 << ' ' << w << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}