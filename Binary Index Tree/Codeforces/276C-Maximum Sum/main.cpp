#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 2e5 + 7;
int bit[maxn];
int n,q;

void update(int id, int v)
{
    while (id <= n)
    {
        bit[id] += v;
        id += (id & (-id));
    }
}

int get(int p)
{
    int res = 0, id = p;
    while (id > 0)
    {
        res += bit[id];
        id -= (id & (-id));
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++)
    {
        int l,r;
        cin >> l >> r;
        update(l, 1);
        update(r+1, -1);
    }

    vector<int> c;
    for (int i = 1; i <= n; i++)
    {
        int k = get(i);
        c.push_back(k);
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i]*c[i];

    cout << ans << '\n';

    return 0;
}