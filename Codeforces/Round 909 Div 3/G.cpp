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

class SegmentTree {
public:
    int n;
    vector<vector<int>> st;

    void build(int p, int l, int r, const vector<int>& arr) {
        if (l == r) {
            st[p].push_back(arr[l]);
            return;
        }

        int m = (l+r)>>1;
        build(2*p, l, m, arr);
        build(2*p+1, m+1, r, arr);
        // sort(all(st[2*p]));
        // sort(all(st[2*p+1]));
        // st[p].resize(st[2*p].size() + st[2*p+1].size());
        merge(all(st[2*p]), all(st[2*p+1]), back_inserter(st[p]));
    }

    bool query(int p, int l, int r, int u, int v, int min, int max) const {
        if (l>v || r<u) return false;
        if (l>=u && r<=v) {
            // check xem trong đoạn [l, r] này có phần tử nào >= min và <= max không
            // st[p] là một sorted vector gồm các phần tử nằm trong đoạn [l, r]
            // st[p][k] là vị trí đầu tiên mà >= min
            int k = lower_bound(st[p].begin(), st[p].end(), min) - st[p].begin();
            if (k < st[p].size() && st[p][k] <= max) return true;
            else return false;
        }
        
        int mid = l + r >> 1;
        bool get1 = query(2*p, l, mid, u, v, min, max);
        bool get2 = query(2*p+1, mid+1, r, u, v, min, max);
        
        return get1 || get2;
    }

    SegmentTree(int size) : n(size), st(4*size) {}
    SegmentTree(const vector<int>& arr)
    : n(arr.size()), st(4*n) {
        if (n > 0) build(1, 0, n-1, arr);
    }

    bool query(int u, int v, int min, int max) const {
        if (u<0) u = 0;
        if (v >= n) v = n-1;
        if (u>v) return false;
        return query(1, 0, n-1, u, v, min, max);
    }
};

int32_t main()
{
    fastio;

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n,q;
        cin >> n >> q;
        vector<vector<int>> g(n);
        for (int i = 0; i < n-1; i++) {
            int u,v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> new_idx(n), treeSize(n, 0);
        int cnt = 0;
        function<void(int,int)> dfs = [&](int u, int par){
            new_idx[u] = cnt++;
            // cout << "visit " << u+1 << '\n';
            treeSize[new_idx[u]] = 1;
            for (auto v : g[u]) {
                if (v == par) continue;
                dfs(v, u);
                treeSize[new_idx[u]] += treeSize[new_idx[v]];
            }
        };
        dfs(0, -1);

        // cout << "new_idx: ";
        // for (auto x : new_idx) cout << x+1 << ' ';
        // cout << '\n';

        // cout << "treeSize : ";
        // for (auto x : treeSize) cout << x << ' ';
        // cout << '\n';

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
            p[i] = new_idx[p[i]];
            // cout << p[i]+1 << ' ';
        }

        SegmentTree st(p);

        while (q--) {
            int l,r,x;
            cin >> l >> r >> x;
            l--, r--, x--;
            int new_x = new_idx[x];
            int lo = new_x, hi = new_x + treeSize[new_x] - 1;
            // cout << "new_x : " << new_x << " lo : " << lo << " hi :" << hi << '\n';
            if (st.query(l, r, lo, hi)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        cout << '\n';
    }

    return 0;
}