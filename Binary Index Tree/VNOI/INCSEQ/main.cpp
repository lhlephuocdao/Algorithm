#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e4 + 7;
const int maxa = 1e5 + 7;
const int MOD = 5e6;

int n,k, a[maxn], v[maxn];
ll dp[maxa+1][55];

void update(int id, int k, ll val)
{
    while (id <= maxa)
    {
        dp[id][k] = (dp[id][k] + val) % MOD;
        id += id & (-id);
    }
}

ll get(int id, int k)
{
    ll ans = 0;
    while (id > 0)
    {
        ans = (ans + dp[id][k]) % MOD;
        id -= id & (-id);
    }
    return ans;
}

void solve()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[i] = a[i];
    }
    sort(v+1, v+n+1);
    int size = unique(v+1, v+n+1)-v-1;
    for (int i = 1; i<=n; i++)
        a[i] = lower_bound(v+1, v+1+size, a[i])-v;

    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        update(x, 1, 1);
        for (int j = 2; j <= k; j++)
        {
            update(x, j, get(x-1, j-1));
        }
    }

    cout << get(maxa, k);    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}