#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 7;
const int inf = 1e9 + 7;

int N,q;
int a[maxN];
long long st[4*maxN], lazy[4*maxN];

void build(int id, int l, int r)
{
    if (l == r) 
    {
        st[id] = a[l];
        return;
    }

    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    st[id] = max(st[id*2], st[id*2+1]);
}

void lazy_update(int id, int l, int r)
{
    if (!lazy[id]) return;
    st[id] += lazy[id];
    
    if (l != r) {
        lazy[2*id] += lazy[id];
        lazy[2*id + 1] += lazy[id];
    }

    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val)
{
    lazy_update(id, l, r);
    if (l>v || r<u) return;

    if (l>=u && r<=v) {
        lazy[id] += val;
        lazy_update(id, l, r);
        return;
    }

    int mid = l + r >> 1;
    update(2*id, l, mid, u, v, val);
    update(2*id+1, mid+1, r, u, v, val);

    st[id] = max(st[2*id], st[2*id+1]);
}

long long get(int id, int l, int r, int u, int v)
{
    lazy_update(id, l, r);
    if (l>v || r<u) return -inf;
    if (l>=u && r<=v) {
        return st[id];
    }

    int mid = l+r >> 1;
    long long get1 = get(id*2, l, mid, u, v);
    long long get2 = get(id*2+1, mid+1, r, u, v);

    return max(get1, get2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(st, 0, sizeof(st));
    memset(lazy, 0, sizeof(lazy));

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
        build(1, 1, N);

    // for (int i = 1; i<=4*N; i++)
    //     cout << st[i] << " ";
    // cout << endl;

    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1) {
            int x,y,val;
            cin >> x >> y >> val;
            update(1,1,N,x,y,val);
        } else {
            int l,r;
            cin >> l >> r;
            cout << get(1,1,N,l,r) << '\n';
        }
    }

    return 0;
}