/*
    https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/increasing-subsequence-1-2d4df2d3/
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define ll long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;
const ll INF = numeric_limits<ll>::max();

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

 struct SegmentTree {
    // 0-based index
    int n;
    vector<ll> st, lazy;

    SegmentTree(int _n) {
        n = _n;
        st.assign(4*n, INF);
        lazy.assign(4*n, 0);
    }

    SegmentTree(vector<int>& a) {
        n = a.size();
        st.assign(4*n, INF);
        lazy.assign(4*n, 0);
        build(1, 0, n-1, a);
    }

    // build from initial array
    void build(int p, int l, int r, const vector<ll> &a) {
        if (l == r) {
            st[p] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(p<<1, l, m, a);
        build(p<<1|1, m+1, r, a);
        st[p] = min(st[p<<1], st[p<<1|1]);
    }

    // propagate lazy value
    void push(int p, int l, int r) {
        if (lazy[p] != 0) {
            st[p] += lazy[p];
            if (l != r) {
                lazy[p<<1] += lazy[p];
                lazy[p<<1|1] += lazy[p];
            }
            lazy[p] = 0;
        }
    }

    // range add update: add `val` to [i..j]
    void update(int p, int l, int r, int i, int j, ll val) {
        push(p, l, r);
        if (r < i || l > j) return;
        if (l >= i && r <= j) {
            lazy[p] += val;
            push(p, l, r);
            return;
        }
        int m = (l + r) >> 1;
        update(p<<1, l, m, i, j, val);
        update(p<<1|1, m+1, r, i, j, val);
        st[p] = min(st[p<<1], st[p<<1|1]);
    }
    void update(int i, int j, ll val) {
        update(1, 0, n-1, i, j, val);
    }

    // range minimum query on [i..j]
    ll query(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (r < i || l > j) return INF;
        if (l >= i && r <= j) return st[p];
        int m = (l + r) >> 1;
        return min(query(p<<1, l, m, i, j),
                   query(p<<1|1, m+1, r, i, j));
    }
    ll query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }
};

int32_t main()
{
    fastio;

    int t = 1;
    while (t--)
    {
        int n,m; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        SegmentTree st(a);
        cin >> m;
        while (m--) {
            int lf, rg;
            ll v;
            // peek next token count
            string line;
            getline(cin, line);
            if (line.empty()) { // read the real line
                getline(cin, line);
            }
            stringstream ss(line);
            vector<ll> tokens;
            ll x;
            while (ss >> x) tokens.push_back(x);

            lf = tokens[0];
            rg = tokens[1];
            if (tokens.size() == 2) {
                if (lf <= rg) { // query [lf, rg]
                    cout << st.query(lf, rg) << '\n';
                } else {
                    // query [lf, n-1] and [0, rg]
                    int ans = min(st.query(lf, n-1), st.query(0, rg));
                    cout << ans << '\n';
                }
            } else {
                v = tokens[2];
                if (lf <= rg) {
                    st.update(lf, rg, v);
                } else {
                    st.update(lf, n-1, v);
                    st.update(0, rg, v);
                }
            }
        }
    }
    return 0;
}