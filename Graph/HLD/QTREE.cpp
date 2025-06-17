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

int n,q;
vector<int> val, par, depth, sz, pos, arr, ChainID, ChainHead;
vector<vector<pii>> g;
int CurChain, CurPos;

void dfs(int u, int p = -1) {
    sz[u] = 1;
    for (auto& [v,w] : g[u]) {
        if (v == p) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        val[v] = w; 
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void hld(int u, int p = -1) {
    if (ChainHead[CurChain] == -1)
        ChainHead[CurChain] = u;
    ChainID[u] = CurChain;
    pos[u] = CurPos;
    arr[CurPos] = u;
    CurPos++;
    int nxt = -1;
    for (auto [v,_] : g[u]) {
        if (v != p)
            if (nxt == -1 || sz[v] > sz[nxt]) nxt = v;
    }
    if (nxt != -1) hld(nxt, u);
    for (auto [v,_] : g[u]) {
        if (v != nxt && v != p) {
            CurChain++;
            hld(v, u);
        }
    }
}

int LCA(int u, int v) {
    while (ChainID[u] != ChainID[v]) {
        if (ChainID[u] > ChainID[v]) {
            u = par[ChainHead[ChainID[u]]];
        } else {
            v = par[ChainHead[ChainID[v]]];
        }
    }
    if (depth[u] < depth[v]) return u;
    return v;
}

// st1 : min
// st2 : max
vector<int> st1, st2;
void build(int id, int l, int r) {
    if (l == r) {
        if (l != 0) {
            st1[id] = val[arr[l]];
            st2[id] = val[arr[l]];
        }
        // cout << "l: " << l << " r: " << r << '\n';
        // cout << "st1[" << id << "] : " << st1[id] << '\n';
        // cout << "st2[" << id << "] : " << st2[id] << '\n';
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st1[id] = min(st1[id*2], st1[id*2+1]);
    st2[id] = max(st2[id*2], st2[id*2+1]);
    // cout << "l: " << l << " r: " << r << '\n';
    // cout << "st1[" << id << "] : " << st1[id] << '\n';
    // cout << "st2[" << id << "] : " << st2[id] << '\n';
}

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r && l == pos) {
        st1[id] = val;
        st2[id] = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*id, l, mid, pos, val);
    update(2*id+1, mid+1, r, pos, val);
    st1[id] = min(st1[id*2], st1[id*2+1]);
    st2[id] = max(st2[id*2], st2[id*2+1]);
}

pii query(int id, int l, int r, int u, int v) {
    if (l>v || r < u) return {INF, -INF};
    if (l>=u && r<=v) return {st1[id], st2[id]};
    int mid = (l+r)/2;
    pii q1 = query(2*id, l, mid, u, v);
    pii q2 = query(2*id+1, mid+1, r, u, v);
    return {min(q1.first, q2.first), max(q1.second, q2.second)};
}

void update(int x, int val) {
    update(1, 0, n-1, pos[x], val);
}

pii query(int u, int v) {
    int lca = LCA(u, v);
    // cout << "u: " << u << " v: " << v << " lca: " << lca << '\n';
    int ans_min = INF, ans_max = -INF;
    while (ChainID[u] != ChainID[lca]) {
        pii p = query(1, 0, n-1, pos[ChainHead[ChainID[u]]], pos[u]);
        ans_min = min(ans_min, p.first);
        ans_max = max(ans_max, p.second);
        u = par[ChainHead[ChainID[u]]];
    }

    while (ChainID[v] != ChainID[lca]) {
        // cout << "pos[ChainHead[ChainID[v]]] " << pos[ChainHead[ChainID[v]]] << '\n';
        // cout << "pos[" << v << "]: " << pos[v] << '\n';
        pii p = query(1, 0, n-1, pos[ChainHead[ChainID[v]]], pos[v]);
        ans_min = min(ans_min, p.first);
        ans_max = max(ans_max, p.second);
        // cout << ans_min << ' ' << ans_max << '\n';
        v = par[ChainHead[ChainID[v]]];
    }
    // cout << "v : " << v << '\n';

    if (depth[u] > depth[v]) swap(u, v);
    // cout << "u: " << u << " v : " << v << '\n';
    // cout << pos[u] << ' ' << pos[v] << '\n';
    pii p = query(1, 0, n-1, pos[u]+1, pos[v]);
    ans_min = min(ans_min, p.first);
    ans_max = max(ans_max, p.second);

    return {ans_min, ans_max};
}

int32_t main()
{
    fastio;

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        cin >> n;

        g         .assign(n, {});
        val       .assign(n, 0);
        par       .assign(n, -1);
        depth     .assign(n, 0);
        sz        .assign(n, 0);
        pos       .assign(n, 0);
        arr       .assign(n, 0);
        ChainID   .assign(n, 0);
        ChainHead .assign(n, -1);
        st1       .assign(4*n, INF);
        st2       .assign(4*n, -INF);

        vector<pii> edges;
        for (int i = 0; i < n-1; i++) {
            int u,v, w;
            cin >> u >> v >> w;
            u--, v--;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            edges.push_back({u, v});
        }

        CurPos = CurChain = 0;
        depth[0] = 0; par[0] = -1;
        dfs(0);
        ChainHead[0] = -1;
        hld(0);

        function<void(vector<int>&)> debug = [&](vector<int>& a){
            for (auto x : a) cout << x << ' ';
            cout << '\n';
        };
        // debug(arr);
        // debug(pos);
        // debug(ChainID);
        // debug(ChainHead);
        // debug(par);
        // debug(depth);
        // debug(sz);
        // debug(val);

        build(1, 0, n-1);
        while (true) {
            string type;
            cin >> type;
            if (type == "QUERY") {
                int a,b;
                cin >> a >> b;
                a--, b--;
                pii p = query(a, b);
                cout << p.second << '\n';
            } else if (type == "CHANGE") {
                int i, val;
                cin >> i >> val;
                i--;
                auto [u, v] = edges[i];
                if (par[v] != u) swap(u,v);
                assert(par[v] == u);
                update(v, val);
            } else break;
        }
    }

    return 0;
}