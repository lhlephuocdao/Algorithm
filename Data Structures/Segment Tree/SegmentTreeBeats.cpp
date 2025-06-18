#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct Node {
    ll sum;
    int mx;
};
 
class SegmentTree {
    int n;
    vector<Node> st;
public:
    SegmentTree(int _n): n(_n) {
        st.assign(4*n+4, {0, 0});
    }
    void build(int p, int l, int r, const vector<int>& a) {
        if (l == r) {
            st[p].sum = a[l];
            st[p].mx = a[l];
        } else {
            int m = (l + r) >> 1;
            build(p<<1, l, m, a);
            build(p<<1|1, m+1, r, a);
            pull(p);
        }
    }
    void pull(int p) {
        st[p].sum = st[p<<1].sum + st[p<<1|1].sum;
        st[p].mx = max(st[p<<1].mx, st[p<<1|1].mx);
    }
    ll query_sum(int p, int l, int r, int i, int j) {
        if (j < l || r < i) return 0;
        if (i <= l && r <= j) return st[p].sum;
        int m = (l + r) >> 1;
        return query_sum(p<<1, l, m, i, j)
             + query_sum(p<<1|1, m+1, r, i, j);
    }
    void point_update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            st[p].sum = val;
            st[p].mx = val;
        } else {
            int m = (l + r) >> 1;
            if (idx <= m) point_update(p<<1, l, m, idx, val);
            else point_update(p<<1|1, m+1, r, idx, val);
            pull(p);
        }
    }
    void range_mod(int p, int l, int r, int i, int j, int x) {
        if (j < l || r < i || st[p].mx < x) return;
        if (l == r) {
            st[p].sum %= x;
            st[p].mx = st[p].sum;
        } else {
            int m = (l + r) >> 1;
            range_mod(p<<1, l, m, i, j, x);
            range_mod(p<<1|1, m+1, r, i, j, x);
            pull(p);
        }
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    SegmentTree st(n);
    st.build(1, 1, n, a);
 
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << st.query_sum(1, 1, n, l, r) << "\n";
        } else if (type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            st.range_mod(1, 1, n, l, r, x);
        } else if (type == 3) {
            int k, x;
            cin >> k >> x;
            st.point_update(1, 1, n, k, x);
        }
    }
 
    return 0;
}