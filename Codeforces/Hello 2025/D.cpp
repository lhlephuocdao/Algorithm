#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
#define INF LLONG_MAX

struct node {
    int r, l, res, pre_max, pre_min, suf_max, suf_min;

    static node base() { return {-1,-1,-INF,-INF,INF,-INF,INF}; }

    static void debug(const node& a) {
        cout << a.r << " " << a.l << " " << a.res << " " << a.pre_max << " " << a.pre_min << ' ' << a.suf_max << ' ' << a.suf_min << '\n';
    }

    static node merge(const node& a, const node& b) {
        node ans;
        
        int l1 = a.l, r1 = a.r, l2 = b.l, r2 = b.r;
        int pre_max1 = a.pre_max, pre_min1 = a.pre_min;
        int suf_max1 = a.suf_max, suf_min1 = a.suf_min;

        int pre_max2 = b.pre_max, pre_min2 = b.pre_min;
        int suf_max2 = b.suf_max, suf_min2 = b.suf_min;

        ans.l = (l1!=-1 ? l1 : l2);
        ans.r = (r2!=-1 ? r2 : r1);
        ans.res = max(a.res, b.res);
        int tmp = max(pre_max2 - suf_min1 - 1, suf_max1 - pre_min2 - 1);
        ans.res = max(ans.res, tmp);

        ans.pre_max = max(pre_max1, pre_max2 - (r1-l1) - 1);
        ans.pre_min = min(pre_min1, (r1-l1) + pre_min2 + 1);
        ans.suf_max = max(suf_max2, suf_max1 - (r2-l2) - 1);
        ans.suf_min = min(suf_min2, suf_min1 + (r2-l2) + 1);

        return ans;
    }
};

void build(int id, int l ,int r, node st[], vector<int>& a) {
    if (l == r) {
        st[id] = {r, l, 0, a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid, st, a);
    build(2 * id + 1, mid + 1, r, st, a);
    st[id] = node::merge(st[2 * id], st[2 * id + 1]);
}

node get(int id, int l, int r, int u, int v, node st[]) {
    if (l >  v || r <  u) return node::base();
    if (l >= u && r <= v) return st[id];
 
    int mid = l + r >> 1;
    node g1 = get(2 * id, l, mid, u, v, st);
    node g2 = get(2 * id + 1, mid + 1, r, u, v, st);
    return node::merge(g1, g2);
}

void update(int id, int l, int r, int x, int y, node st[])
{
    if (l > x || r < x) return;

    if (l == r) {
        st[id] = {r, l, 0, y, y, y, y};
        return;
    }

    int mid = l + r >> 1;
    update(id*2, l, mid, x, y, st);
    update(id*2+1, mid+1, r, x, y, st);
 
    st[id] = node::merge(st[2 * id], st[2 * id + 1]);
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t; cin >> t;
    while (t--)
    {
        int n,q;
        cin >> n >> q;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        node st[4 * n];
        for (int i = 0; i < 4*n; i++) st[i] = node::base();
        build(1, 1, n, st, a);
        cout << get(1, 1, n, 1, n, st).res << '\n';

        while (q--)
        {
            int p,x;
            cin >> p >> x;
            a[p] = x;
            update(1, 1, n, p, x, st);
            cout << get(1, 1, n, 1, n, st).res << '\n';
        }
    }

    return 0;
}