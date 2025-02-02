#include <bits/stdc++.h>

using namespace std;

const int maxn = 30007;
const int maxa = 1e4+7;
const int block = 400;

int n, q, a[maxn], st[80][4*maxa];

void update(int block, int id, int l, int r, int x, int val)
{
    if (l>x || r<x) return;
    if (l == r) {
        st[block][id] += val;
        return;
    }
    int mid = l + r >> 1;
    update(block, 2*id, l, mid, x, val);
    update(block, 2*id+1, mid+1, r, x, val);

    st[block][id] = st[block][2*id] + st[block][2*id+1];
}

int get(int block, int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) return st[block][id];

    int mid = l + r >> 1;
    int get1 = get(block, 2*id, l, mid, u, v);
    int get2 = get(block, 2*id+1, mid+1, r, u, v);

    return get1+get2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i/block, 1, 1, maxa, a[i], 1);
    }

    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if (t == 0) {
            int i, v;
            cin >> i >> v;
            update(i/block, 1, 1, maxa, a[i], -1);
            update(i/block, 1, 1, maxa, v, 1);
            a[i] = v;
        } else if (t == 1) {
            int l,r,k;
            cin >> l >> r >> k;
            int ans = 0;
            while (l<=r && l%block!=0) ans += a[l++] > k;
            while (l<=r && r%block!=0) ans += a[r--] > k;

            if (l < r) {
                int nl = l/block;
                int nr = r/block;
                for (int i = nl; i <= nr; i++)
                    ans += get(i, 1, 1, maxa, k+1, maxa);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}