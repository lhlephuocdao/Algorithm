#include <bits/stdc++.h>

using namespace std;

int n,q;
const int maxN = 1e5 + 7;
long long st[4*maxN];

void update(int id, int l, int r, int x, int y)
{
    if (l > x || r < x) return;

    if (l == r) {
        st[id] = y;
        return;
    }

    int mid = l + r >> 1;
    update(id*2, l, mid, x, y);
    update(id*2+1, mid+1, r, x, y);

    st[id] = st[id*2] + st[id*2+1];
}

long long get(int id, int l, int r, int u, int v)
{
    if (r < u || l > v) return 0;

    if (l >= u && r <= v) return st[id];

    int mid = l + r >> 1;
    long long get1 = get(id*2, l, mid, u, v);
    long long get2 = get(id*2+1, mid+1, r, u, v);

    return get1 + get2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    while (q--)
    {
        int t,a,b;
        cin >> t >> a >> b;
        if (t==1) update(1,1,n,a,b);
        else cout << get(1,1,n,a,b) << '\n';
    }
    
    return 0;
}