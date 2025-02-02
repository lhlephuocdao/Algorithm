#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int mod = 1e9 + 7;
ll A, B;

map<ll, ll> factorize(ll n) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1) {
        res[n]++;
    }
    return res;
}

ll exp(ll x, ll n, ll m) {
	assert(n >= 0);
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    #if 1
    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);
    #endif

    cin >> A >> B;
    if (B == 0) {
        cout << 1 << '\n';
        return 0;
    }
    map<ll, ll> f = factorize(A);
    ll sum = 1;
    for (auto itr = f.begin(); itr != f.end(); itr++)
    {
        ll p = itr->first;
        ll a = itr->second;

        if ((p-1) % mod != 0) {
            sum *= ((((exp(p, (a*(B%(mod-1))+1)%(mod-1), mod)-1+mod)%mod)*exp(p-1, mod-2, mod))%mod) % mod;
            sum %= mod;
        } else {
            ll BB = B;
            BB %= mod;
            ll t = (BB*a%mod + 1)%mod;
            sum *= t;
            sum %= mod;
        }
    }

    cout << sum << '\n';

    return 0;
}