#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int maxn = 1e6+7;
const int mod = 998244353;
int n;
vector<int> a[maxn];
map<int, int> m;

ll exp(ll x, ll n, ll m) {
	assert(n >= 0);
	x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
            m[a[i][j]]++;
        }
    }

    ll inverse_n = exp(n, mod-2, mod);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int k = a[i].size();
        ll inverse_k = exp(k, mod-2, mod);
        for (auto y : a[i]) {
            ans += ((((inverse_n%mod)*(inverse_k%mod))%mod)*(((m[y]%mod)*(inverse_n%mod))%mod))%mod;
            ans %= mod;
        }
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