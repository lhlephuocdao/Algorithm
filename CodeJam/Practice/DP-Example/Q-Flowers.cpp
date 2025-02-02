#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 2e5;
ll n;
ll bit[maxn + 7];

void update(ll u, ll v) {
    ll idx = u;
    while (idx <= n) {
        bit[idx] = max(bit[idx], v);
        idx += (idx & (-idx));
    }
}

ll getSum(ll idx)
{
    ll ans = 0;
    while (idx > 0) {
        ans = max(ans, bit[idx]);
        idx -= (idx & (-idx));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    memset(bit, 0, sizeof(bit));

    vector<ll> h(n), a(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        ll sum = getSum(h[i]-1);
        dp[i] = a[i] + sum;
        update(h[i], dp[i]);
    }

    cout << getSum(n) << '\n';

    return 0;
}