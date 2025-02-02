#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e5 + 7;

void build(int st[], int id, int l ,int r, vector<int>& dif) {
    if (l > r) return;
    if (l == r) {
        st[id] = dif[l];
        return;
    }
    int mid = l + r >> 1;
    build(st, 2 * id, l, mid, dif);
    build(st, 2 * id + 1, mid + 1, r, dif);
    st[id] = __gcd(st[2*id], st[2*id + 1]);
}

long long get(int st[], int id, int l, int r, int u, int v)
{
    if (r < u || l > v) return 0;

    if (l >= u && r <= v) return st[id];

    int mid = l + r >> 1;
    long long get1 = get(st, id*2, l, mid, u, v);
    long long get2 = get(st, id*2+1, mid+1, r, u, v);

    return __gcd(get1,get2);
}

void solve()
{
    int n, q; cin >> n >> q;
    int st[4*n];

    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> dif(n+1, 0);
    for (int i = 1; i < n; i++)
        dif[i] = abs(a[i+1] - a[i]);

    build(st, 1, 1, n-1, dif);

    while (q--)
    {
        int l,r;
        cin >> l >> r;
        if (n > 1) {
            if (r>l)
                cout << get(st, 1, 1, n-1, l, r-1) << " ";
            else
                cout << 0 << " ";
        }
        else
            cout << 0 << " ";
    }
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}