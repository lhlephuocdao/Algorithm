#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e5 + 7;
int n,k;
ll dp[maxn+1][20];

void update(int id, int k, ll val)
{
    while (id <= maxn)
    {
        dp[id][k] += val;
        id += id & (-id);
    }
}

ll get(int id, int k)
{
    ll ans = 0;
    while (id > 0)
    {
        ans += dp[id][k];
        id -= id & (-id);
    }
    return ans;
}

void solve()
{
    cin >> n >> k;
    k++;

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        update(x, 1, 1);
        for (int j = 2; j <= k; j++)
        {
            ll sum = get(x-1, j-1);
            update(x, j, sum);
        }
    }

    cout << get(maxn, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}