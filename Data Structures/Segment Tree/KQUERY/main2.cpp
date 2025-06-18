#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
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

// 0-based index
class SegmentTree {
private:
    int n;
    vector<int> st;

    void build(int p, int l, int r, const vector<int>& arr) {
        if (l == r) {
            st[p] = arr[l];
            return;
        }
        int m = (l+r)>>1;
        build(2*p, l, m, arr);
        build(2*p+1, m+1, r, arr);
        st[p] = st[2*p] + st[2*p+1];
    }

    // query minimum on inverval [i, j]
    int query(int p, int l, int r, int i, int j) const {
        if (r<i || l>j) return 0;
        if (l>=i && r<=j) return st[p];
        int m = (l+r)>>1;
        int v1 = query(2*p, l, m, i, j);
        int v2 = query(2*p+1, m+1, r, i, j);
        return v1 + v2;
    }

    // update set arr[idx] = val
    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            st[p] = val;
            return;
        }
        int m = (l+r)>>1;
        if (idx<=m)
            update(2*p, l, m, idx, val);
        else
            update(2*p+1, m+1, r, idx, val);
        st[p] = st[2*p] + st[2*p+1];
    }
public:
    SegmentTree(int size) : n(size), st(4*size, 0) {}
    SegmentTree(const vector<int>& arr)
        : n(arr.size()), st(4*n, 0)
    {
        if (n>0) build(1, 0, n-1, arr);
    }

    int query(int l, int r) const {
        if (l<0) l = 0;
        if (r >= n) r = n-1;
        if (l>r) return 0;
        return query(1, 0, n-1, l, r);
    }

    void update(int idx, int val) {
        if (idx < 0 || idx >= n) return;
        update(1, 0, n-1, idx, val);
    }
};

int32_t main()
{
    fastio;

    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        int n; cin >> n;
        SegmentTree st(n);
        for (int i = 0; i < n; i++) st.update(i, 1);
        
        vector<pii> a(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] = {x, i};
        }
        
        struct query {
            int l, r, k, idx;
        };
        int q; cin >> q;
        vector<query> que(q);
        for (int i = 0; i < q; i++) {
            int x,y,k;
            cin >> x >> y >> k;
            x--, y--;
            que[i] = {x, y, k, i};
        }

        sort(all(a));
        sort(all(que), [](const query& q1, const query& q2){
            return q1.k < q2.k;
        });

        vector<int> ans(q);
        for (int i = 0, j = 0; i < q; i++) {
            int k = que[i].k;
            while (j<n && a[j].first <= k) {
                int idx = a[j].second;
                st.update(idx, 0);
                j++;
            }

            ans[que[i].idx] = st.query(que[i].l, que[i].r);
        }

        for (auto x : ans) cout << x << '\n';
    }

    return 0;
}