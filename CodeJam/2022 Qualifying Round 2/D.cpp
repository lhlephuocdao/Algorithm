#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;
const int INF = 1e18;

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
    // f[u] : sum of w from root to u
    // f2[v] : sum of (a[v] - b[v])*w from root to v
    vector<int> h, f, f2, a, b;
    vector<vector<int>> up;

    LCA(vector<vector<pii>>& g, int r, vector<int>& _a, vector<int>& _b) {
        root = r;
        int n = g.size();
        log = __lg(n);
        h.assign(n, 0);
        f.assign(n, 0);
        f2.assign(n, 0);
        a = _a;
        b = _b;
        up.assign(n, vector<int>(log+1));
        dfs(root, g);
    }

    void dfs(int u, vector<vector<pii>>& g) {
        for (auto& [v,w] : g[u]) {
            if (v == up[u][0]) continue;
            h[v] = h[u] + 1;
            f[v] = f[u] + w;
            f2[v] = f2[u] + (a[v] - b[v])*w;

            up[v][0] = u; // parent of v is u
            for (int j = 1; j <= log; ++j) {
                up[v][j] = up[up[v][j - 1]][j - 1];
            }

            dfs(v, g);
            // cout << "f2[" << v << "] : " << f2[v] << '\n';
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

    // first : sum of w from u1 to lca(u1,u2)
    // second : sum of w from u2 to lca(u1,u2)
    pii sum_w(int u1, int u2) {
        int p = lca(u1, u2);
        return {f[u1] - f[p], f[u2] - f[p]};
    }

    // first : sum of (a[u1]-b[u1])*w from lca(u1,u2) to u1
    // second : sum of (a[u2]-b[u2])*w from lca(u1,u2) to u2
    pii sum2(int u1, int u2) {
        int p = lca(u1, u2);
        return {f2[u1] - f2[p], f2[u2] - f2[p]};
    }

    void debug_w() {
        int n = f.size();
        cout << "debug weight : \n";
        for (int i = 0; i < n; i++) {
            cout << "f[" << i << "] : " << f[i] << '\n';
        }
    }

    int dis(int u, int v) {
        int r = lca(u, v);
        return f[u] + f[v] - 2*f[r];
    }
};

int32_t main()
{
    fastio;

    int tc = 1; cin >> tc;
    while (tc--)
    {
        int n,m; cin >> n >> m;
        vector<vector<pii>> g(n);
        vector<pair<pii,pii>> edges; // {{index,w},{u,v}}
        for (int i = 0; i < n-1; i++) {
            int u,v,w;
            cin >> u >> v >> w;
            u--, v--;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            edges.push_back({{i,w}, {u,v}});
        }

        // a[u] : size của subtree tại u (bao gồm cả u)
        // b[u] : size của root tree sau khi exclude subtree tại u
        // b[u] = n - a[u]
        vector<int> a(n, 0), b(n, 0);
        int score = 0;
        function<void(int,int)> dfs = [&](int u, int par){
            a[u] = 1;
            for (auto& [v,w] : g[u]) {
                if (v == par) continue;
                dfs(v, u);
                // edge u-v có trọng số w
                // contribute: a[v]*w*b[v]
                score += a[v]*w*b[v];
                a[u] += a[v];
            }
            b[u] = n - a[u];
        };
        dfs(0, -1);

        int root = 0;
        LCA lca(g, root, a, b);
        // lca.debug_w();

        // auto [s1, s2] = lca.sum2(4, 2);
        // cout << s1 << ' ' << s2 << '\n';

        int min_score = INF, max_score = -INF;
        while (m--) {
            // u2,v2 : edge to be added
            int idx,u2,v2,w;
            cin >> idx >> u2 >> v2 >> w;
            idx--, u2--, v2--;

            pair<pii,pii> edge = edges[idx];
            // u1,v1 : edge to be removed
            auto [u1,v1] = edge.second;
            // make sure that u1 is parent of v1
            if (lca.h[u1] > lca.h[v1]) swap(u1,v1);
            int old_w = edge.first.second;

            int x = a[v1], y = b[v1];
            int new_score = score - x*y*old_w + x*y*w;

            // make sure v2 is the node in the subtree of v1
            // v1 là tổ tiên của v2
            {
                int ancestor = lca.lca(v1, v2);
                if (ancestor != v1) {
                    // cout << "swap " << u2 << " and " << v2 << '\n';
                    swap(u2, v2);
                }
            }

            // s1 : sum of (a[u1]-b[u1])*w from lca(u1,u2) to u1
            // s2 : sum of (a[u2]-b[u2])*w from lca(u1,u2) to u2
            auto [s1, s2] = lca.sum2(u1, u2);
            // sw1 : sum of w from u1 to lca(u1,u2)
            // sw2 : sum of w from u2 to lca(u1,u2)
            auto [sw1, sw2] = lca.sum_w(u1, u2);
            new_score += s1*x - sw1*x*x;
            new_score += -s2*x - sw2*x*x;

            new_score += -lca.sum2(v1, v2).second*y - lca.sum_w(v1,v2).second*y*y;

            min_score = min(min_score, new_score);
            max_score = max(max_score, new_score);
        }

        cout << score << ' ' << min_score << ' ' << max_score << '\n';
    }
    return 0;
}