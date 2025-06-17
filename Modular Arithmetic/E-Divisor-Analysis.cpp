#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 7;
int n, x[maxn], k[maxn];

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

    cin >> n;
    ll num = 1;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> k[i];
        num = num * (k[i]+1);
        num %= mod;
    }

    ll sum = 1, product = 1;
    bool isOdd = false;
    ll odd_index = -1;
    for (int i = 0; i < n; i++)
    {
        int p = x[i], a = k[i];
        if (a%2 == 1) {
            isOdd = true;
            odd_index = i;
        }

        sum *= (((exp(p, a+1, mod) - 1 + mod)%mod)*exp(p-1, mod-2, mod))%mod;
        sum %= mod;
    }

    if (isOdd) {
        ll pow = 1;
        for (int i = 0; i < n; i++)
            if (i == odd_index) {
                pow *= (k[i]+1)/2;
                pow %= mod-1;
            } else {
                pow *= (k[i]+1);
                pow %= mod-1;
            }

        for (int i = 0; i < n; i++)
        {
            product *= exp(x[i], (k[i]*pow)%(mod-1), mod);
            product %= mod;
        }
    } else {
        ll pow = 1;
        for (int i = 0; i < n; i++)
            pow = (pow * (k[i]+1))%(mod-1);
        for (int i = 0; i < n; i++)
        {
            product *= exp(x[i], ((k[i]/2)*pow)%(mod-1), mod);
            product %= mod;
        }
    }

    cout << num << " " << sum << " " << product << '\n';

    return 0;
}