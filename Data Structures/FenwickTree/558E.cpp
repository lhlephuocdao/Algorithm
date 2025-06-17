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
        st.assign(4*n, 0);
        lazy.assign(4*n, -1);
    }

    SegmentTree(vector<int>& a) {
        n = a.size();
        st.assign(4*n, 0);
        lazy.assign(4*n, -1);
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
        st[p] = st[p<<1] + st[p<<1|1];
    }

    // propagate lazy value
    void push(int p, int l, int r) {
        if (lazy[p] != -1) {
            st[p] = (r - l + 1) * lazy[p];
            if (l != r) {
                lazy[p<<1] = lazy[p];
                lazy[p<<1|1] = lazy[p];
            }
            lazy[p] = -1;
        }
    }

    // range add update: assign `val` to [i..j]
    void update(int p, int l, int r, int i, int j, ll val) {
        push(p, l, r);
        if (r < i || l > j) return;
        if (l >= i && r <= j) {
            lazy[p] = val;
            push(p, l, r);
            return;
        }
        int m = (l + r) >> 1;
        update(p<<1, l, m, i, j, val);
        update(p<<1|1, m+1, r, i, j, val);
        st[p] = st[p<<1] + st[p<<1|1];
    }
    void update(int i, int j, ll val) {
        update(1, 0, n-1, i, j, val);
    }

    // range sum query on [i..j]
    ll query(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (r < i || l > j) return 0;
        if (l >= i && r <= j) return st[p];
        int m = (l + r) >> 1;
        return query(p<<1, l, m, i, j) + query(p<<1|1, m+1, r, i, j);
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
        int n,q; cin >> n >> q;
        string s; cin >> s;
        vector<vector<int>> a(26, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            a[c][i] = 1;
        }

        vector<SegmentTree> st(26, SegmentTree(n));
        for (int i = 0; i < 26; i++) {
            st[i].build(1, 0, n-1, a[i]);
        }

        while (q--) {
            int l,r,k;
            cin >> l >> r >> k;
            l--, r--;
            vector<int> cnt(26, 0);
            for (int c = 0; c < 26; c++) {
                cnt[c] = st[c].query(l, r);
                if (cnt[c] > 0) st[c].update(l, r, 0);
            }

            int len = r-l+1;
            int sign = (k == 1) ? 1 : -1;
            int i = l;
            for (int c = (k==1)?0:25 ; c < 26 && c >= 0; c += sign) {
                if (cnt[c] > 0) {
                    st[c].update(i, i+cnt[c]-1, 1);
                    i += cnt[c];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 26; c++) {
                if (st[c].query(i, i) > 0)
                    cout << char(c+'a');
            }
        }
    }
    return 0;
}