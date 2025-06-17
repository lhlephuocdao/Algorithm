#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    int n;
    vector<int> parent, size;
    
    DSU(int n_) : n(n_), parent(n_+1), size(n_+1, 1) {
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    
    int find(int a) {
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
    
    int merge(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return a;
        if (size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
        return a;
    }
};

struct Edge { int u, v; int w; };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> D(N+1);
    for (int i = 1; i <= N; i++) cin >> D[i];
    vector<Edge> edges;
    edges.reserve(M);
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        // weight of this edge = max danger of its two endpoints
        edges.push_back({u, v, max(D[u], D[v])});
    }
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){ return a.w < b.w; });
    
    DSU dsu(N);
    vector<int> rep(N+1);
    for (int i = 1; i <= N; i++) rep[i] = i;
    int tot = N;    // counter over “real + virtual” nodes
    int maxNodes = 2 * N;   // at most N−1 merges ⇒ ≤2N−1 total
    vector<vector<int>> children(maxNodes + 1);
    vector<ll> weight(maxNodes + 1, 0);
    
    for (auto &e : edges) {
        int fu = dsu.find(e.u);
        int fv = dsu.find(e.v);
        if (fu != fv) {
            ++tot;                          // create a new virtual node
            weight[tot] = e.w;              // its weight = this merge’s bottleneck
            children[tot].push_back(rep[fu]);
            children[tot].push_back(rep[fv]);
            // merge the two DSU components
            int newRoot = dsu.merge(fu, fv);
            // record that for this merged component, its representative in the tree is ‘tot’
            rep[newRoot] = tot;
        }
    }
    int final_dsuroot = dsu.find(1);
    // find virtual root
    int root = rep[final_dsuroot];

    vector<ll> leaf(tot+1, 0);
    function<void(int)> dfs1 = [&](int u) {
        if (children[u].empty()) {
            // u is a leaf in the DSU-tree ⇒ an original intersection
            leaf[u] = 1;
        } else {
            leaf[u] = 0;
            for (int v : children[u]) {
                dfs1(v);
                leaf[u] += leaf[v];
            }
        }
    };
    dfs1(root);

    // G[u] will end up = sum of f(u, V) over all original V in u's subtree and elsewhere
    vector<ll> G(tot+1, 0);
    function<void(int)> dfs2 = [&](int u) {
        for (int v : children[u]) {
            // When you go from parent u to child v,
            // exactly leaf[v] leaves stay under v (they use a lower LCA),
            // and (leaf[u] - leaf[v]) leaves “jump up” to use the LCA at u instead,
            // each contributing weight[u] instead of something lower.
            G[v] = G[u] + (leaf[u] - leaf[v]) * weight[u];
            dfs2(v);
        }
    };
    G[root] = 0; // at the very top, there are no “above” contributions
    dfs2(root);

    // output result for original nodes
    // SU = G[i] + D[i]
    for (int i = 1; i <= N; i++) {
        cout << G[i] + D[i] << (i==N? '\n' : ' ');
    }
    return 0;
}
