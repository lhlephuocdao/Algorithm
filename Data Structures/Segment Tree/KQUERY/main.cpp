#include <bits/stdc++.h>
 
using namespace std;

const int maxN = 30007;
int a[maxN];
multiset<int> st[4*maxN];
int n,q;

void build(int id, int l, int r)
{
    if (l == r) {
        st[id].insert(a[l]);
        return;
    }

    int mid = l + r >> 1;
    build(2*id, l, mid);
    build(2*id + 1, mid + 1, r);

    st[id] = st[2*id];
    for (auto x : st[2*id+1]) st[id].insert(x);
}

int get(int id, int l, int r, int u, int v, int val)
{
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) {
        int ans = std::distance(st[id].upper_bound(val), st[id].end());
        return ans;
    }

    int mid = l + r >> 1;
    int get1 = get(2*id, l, mid, u, v, val);
    int get2 = get(2*id + 1, mid+1, r, u, v, val);

    return get1 + get2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    cin >> q;
    while(q--)
    {
        int i,j,k;
        cin >> i >> j >> k;
        cout << get(1, 1, n, i, j, k) << '\n';
    }

    return 0;
}