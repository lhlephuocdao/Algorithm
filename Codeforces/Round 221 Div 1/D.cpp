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

struct Node {
    map<int, int> cnt;
    vector<int> v;
    
    static Node merge(const Node& a, const Node& b) {
        Node res;
        res.cnt = a.cnt;
        for (auto itr : b.cnt)
        {
            int key = itr.first;
            int val = itr.second;
            res.cnt[key] += val;
        }

        for (auto itr : res.cnt)
            res.v.push_back(itr.second);
        sort(all(res.v));

        return res;
    }
};

class SegmentTree {
public:
    int n;
    vector<Node> st;

    void build(int p, int l, int r, const vector<int>& arr) {
        if (l == r) {
            auto& m = st[p].cnt;
            m[arr[l]]++;
            for (auto itr : m) st[p].v.push_back(itr.second);
            sort(all(st[p].v));
            return;
        }

        int m = (l+r)>>1;
        build(2*p, l, m, arr);
        build(2*p+1, m+1, r, arr);
        st[p] = Node::merge(st[2*p], st[2*p+1]);
    }

    Node query(int p, int l, int r, int u, int v) const {
        if (l>v || r<u) return Node();
        if (l>=u && r<=v) {
            return st[p];
        }
        
        int mid = l + r >> 1;
        Node get1 = query(2*p, l, mid, u, v);
        Node get2 = query(2*p+1, mid+1, r, u, v);
        
        return Node::merge(get1, get2);
    }

    SegmentTree(int size) : n(size), st(4*size) {}
    SegmentTree(const vector<int>& arr)
    : n(arr.size()), st(4*n) {
        if (n > 0) build(1, 0, n-1, arr);
    }

    Node query(int u, int v) const {
        if (u<0) u = 0;
        if (v >= n) v = n-1;
        if (u>v) return Node();
        return query(1, 0, n-1, u, v);
    }
};

int32_t main()
{
    fastio;

    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        vector<int> c(n);
        for (auto& x : c) cin >> x;
        for (int i = 0; i < n-1; i++) {
            int u,v; cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> new_idx(n), treeSize(n), new_color(n);
        int cnt = 0;
        function<void(int,int)> dfs = [&](int u, int par){
            new_idx[u] = cnt++;
            treeSize[new_idx[u]] = 1;
            for (auto v : g[u]) {
                if (v == par) continue;
                dfs(v, u);
                treeSize[new_idx[u]] += treeSize[new_idx[v]];
            }
        };
        dfs(0, -1);

        for (int i = 0; i < n; i++)
            new_color[new_idx[i]] = c[i];

        function<void(vector<int>)> debug = [&](vector<int> p) {
            for (auto x : p) cout << x << ' ';
            cout << '\n';
        };

        // debug(new_idx);
        // debug(new_color);
        // debug(treeSize);

        SegmentTree st(new_color);
        while (m--) {
            int x,k;
            cin >> x >> k;
            x--;
            int lo = new_idx[x], hi = lo + treeSize[lo] - 1;
            vector<int> v = st.query(lo, hi).v;
            int idx = lower_bound(v.begin(), v.end(), k) - v.begin();
            cout << v.size() - idx << '\n';
        }
    }

    return 0;
}