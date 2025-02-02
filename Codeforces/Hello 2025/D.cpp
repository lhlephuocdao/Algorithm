#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
    int _min, _max, res;

    static node base() { return {INT_MAX, INT_MIN, -1}; }

    static void debug(const node& a) {
        cout << a._min << " " << a._max << " " << a.res << "\n";
    }

    static node merge(const node& a, const node& b) {
        node ans;
        cout << "a: " ;
        debug(a);
        cout << "b: ";
        debug(b);
        int _max1 = a._max;
        int _max2 = b._max;
        int _min1 = a._min;
        int _min2 = b._min;
        ans._min = min(_min1, _min2);
        ans._max = max(_max1, _max2);
        ans.res = ans._max - ans._min;
        cout << "ans: ";
        debug(ans);
        return ans;
    }
};

void build(int id, int l ,int r, node st[], vector<int>& a) {
    if (l == r) {
        st[id] = {a[r]-r, a[l]-l, 0};
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid, st, a);
    build(2 * id + 1, mid + 1, r, st, a);
    cout << "merge " << 2*id << " and " << 2*id + 1 << '\n';
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
        st[id] = {y-l, y-r, 0};
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
    static int count = 0;
    while (t--)
    {
        int n,q;
        cin >> n >> q;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        node st[4 * n];
        for (int i = 0; i < 4*n; i++) st[i] = node::base();
        build(1, 1, n, st, a);

        // for (int i = 1; i < 4*n; i++) cout << st[i].res << " ";
        // cout << '\n';

        count++;
        cout << get(1, 1, n, 1, n, st).res << '\n';

        while (q--)
        {
            int p,x;
            cin >> p >> x;
            a[p] = x;
            update(1, 1, n, p, x, st);
            //count++;
      
            
            cout << get(1, 1, n, 1, n, st).res << '\n';
        }
    }

    return 0;
}