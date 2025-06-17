#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 2e5 + 7;
const int maxa = 1e9 + 7;

int n;
ll pre[maxn], suf[maxn];
map<ll, int> m;

void solve()
{
    pre[0] = 0; suf[0] = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        pre[i] = pre[i-1] + a;
    }

    ll ans = 0;
    m[0] = 0;
    int l = 1, r = 1;
    while (l <= r && r <= n)
    {
        ll s = pre[r];
        if (m.find(s) != m.end()) l = std::max(l, m[s]+2);

        cout << r << " " << l << '\n';
        ans += r-l+1;
        m[s] = r;
        r++;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}