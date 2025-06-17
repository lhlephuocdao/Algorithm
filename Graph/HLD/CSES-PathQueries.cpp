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
vector<int> v, par, depth, sz, pos, arr, ChainID, ChainHead;
vector<vector<int>> g;
int CurChain, CurPos;

void dfs(int u, int p = -1) {
    sz[u] = 1;
    for (auto v : g[u]) {
        if (v == p) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
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
    for (int v : g[u]) {
        if (v != p)
            if (nxt == -1 || sz[v] > sz[nxt]) nxt = v;
    }
    if (nxt != -1) hld(nxt, u);
    for (int v : g[u]) {
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

vector<int> st;
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = v[arr[l]];
        // cout << "l: " << l << " r: " << r << " st[" << id << "] : " << st[id] << '\n';
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = st[id*2] + st[id*2+1];
    // cout << "l: " << l << " r: " << r << " st[" << id << "] : " << st[id] << '\n';
}

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r && l == pos) {
        st[id] = val;
        return;
    }
    int mid = (l+r)/2;
    update(2*id, l, mid, pos, val);
    update(2*id+1, mid+1, r, pos, val);
    st[id] = st[2*id] + st[2*id+1];
}

int query(int id, int l, int r, int u, int v) {
    if (l>v || r < u) return 0;
    if (l>=u && r<=v) return st[id];
    int mid = (l+r)/2;
    int q1 = query(2*id, l, mid, u, v);
    int q2 = query(2*id+1, mid+1, r, u, v);
    return q1+q2;
}

void update(int x, int val) {
    update(1, 0, n-1, pos[x], val);
}

int query(int u) {
    int ans = 0;
    while (ChainID[u] != ChainID[0]) {
        ans += query(1, 0, n-1, pos[ChainHead[ChainID[u]]], pos[u]);
        u = par[ChainHead[ChainID[u]]];
    }

    ans += query(1, 0, n-1, 0, pos[u]);
    return ans;
}

int32_t main()
{
    fastio;

    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        cin >> n >> q;
        v.resize(n); par.resize(n); depth.resize(n, 0); sz.resize(n); pos.resize(n);
        g.resize(n); arr.resize(n); ChainID.resize(n); ChainHead.assign(n, -1);
        st.resize(4*n);
        for (auto& x : v) cin >> x;
        for (int i = 0; i < n-1; i++) {
            int u,v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        /*
            Your task is to process following types of queries:
            1. change the value of node s to x
            2. calculate the sum of values on the path from the root to node s

            Finally, there are q lines describing the queries.
            Each query is either of the form "1 s x" or "2 s".
        */

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

        build(1, 0, n-1);
        while (q--) {
            int type; cin >> type;
            if (type == 1) {
                int s,x; cin >> s >> x;
                s--;
                update(s, x);
            } else {
                int s; cin >> s;
                s--;
                cout << query(s) << '\n';
            }
        }
    }

    return 0;
}