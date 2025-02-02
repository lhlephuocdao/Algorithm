#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e5 + 7;
const int MAX = 1e9 + 7;
int n,q;
int a[maxn];
ll BIT1[maxn], BIT2[maxn];

void updateBIT(ll BIT[], int id, ll val)
{
    while (id <= n)
    {
        BIT[id] += val;
        id += id & (-id);
    }
}

void update(int l, int r, ll val)
{
    //BIT1
    updateBIT(BIT1, l, val);
    updateBIT(BIT1, r+1, -val);

    //BIT2
    updateBIT(BIT2, l, val*(l-1));
    updateBIT(BIT2, r+1, -val*r);
}

ll getSum(ll BIT[], int id)
{
    ll ans = 0;
    while (id > 0)
    {
        ans += BIT[id];
        id -= id & (-id);
    }
    return ans;
}

ll getSum(int k)
{
    return (getSum(BIT1,k)*k) - getSum(BIT2, k);
}

ll getRangeSumQuerry(int l, int r)
{
    return getSum(r) - getSum(l-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, i, a[i]);
    }

    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            ll x; cin >> x;
            update(l, r, x);
        } else {
            cout << getRangeSumQuerry(l, r) << '\n';
        }
    }

    return 0;
}