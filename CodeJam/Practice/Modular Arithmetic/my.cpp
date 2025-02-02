#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long

const int mod = 86400;
int n;

ll gcd(ll A, ll B) {
    if (B == 0) return A;
    else return gcd(B, A % B);
}

ll lcm(ll a, ll b)
{
    return (a/gcd(a,b))*b;
}

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

int phi(long long n) {
        long long r = n;
        for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                        while (n % i == 0)
                                n /= i;
                        r -= r / i;
                }
        }
        if (n > 1)
                r -= r / n;
        return r;
}

void solve()
{
    cin >> n;
    int T[n], D[n];
    bool check = true, check2 = true;
    vector<int> X(mod + 1, -1), cnt(mod + 1);
    for (int i = 0; i < n; i++)
    {
        string str; cin >> str;
        int h = std::stoi(str.substr(0, 2));
        int m = std::stoi(str.substr(3, 2));
        int s = std::stoi(str.substr(6, 2));
        T[i] = h*3600 + m*60 + s;
        cout << T[i] << " ";
        if (check && i > 0 && T[i] != T[i-1]) check = false;
    }

    for (int i = 0; i < n; i++) {
        cin >> D[i];
        // D[i] = (D[i] + mod) % mod;
        cout << "D[" << i << "]: " << D[i] << '\n';
        if (check2 && i > 0 && (D[i]%mod) != (D[i-1]%mod)) check2 = false;
    }

    if (check && check2) {
        cout << 86400 << '\n';
        return;
    }

    int x[n];
    for (int i = 1; i < n; i++) {
        int DD = ((D[0]%mod-D[i]%mod)%mod + mod)%mod;
        int TT = (T[i] - T[0] + mod) % mod;
        cout << "DD: " << DD << " TT: " << TT << '\n';
        int G = gcd(DD, mod);
        cout << "gcd: " << G << '\n';
        if (TT % G != 0) {
            cout << 0 << '\n';
            return;
        }

        if (DD == 0) {
            if (TT != 0) {
                cout << 0 << '\n';
                return;
            } else {
                x[i-1] = -1;
                cout << "x[" << i-1 << "]: " << x[i-1] << "\n";
                continue;
            }
        }

        int t = TT/G, d = DD/G, m = mod/G;
        int inverse_d = exp(d, phi(m)-1, m);

        x[i-1] = (t*inverse_d + m)%m;
        if (X[m] >= 0 && X[m] != x[i-1]){
            cout << 0 << '\n';
            return;
        }
 
                X[m] = x[i-1];
                ++cnt[m];
        cout << "x[" << i-1 << "]: " << x[i-1] << "\n";
    }
    // cout << '\n';

        int ans = 0;
        vector<int> total(mod + 1);
        for (int m = 1; m <= mod; ++m) {
                if (X[m] < 0)
                        continue;
                for (int x = X[m]; x < mod; x += m) {
                        total[x] += cnt[m];
                        if (total[x] + 1 == n)
                                ++ans;
                }
        }
        cout << ans << '\n';
        return;
#if 0
    int t = 0, id = 0;
    while(id < n-1) {
        if (x[id] > 0) {
            t = x[id];
            break;
        }
        id++;
    }

    for (int i = 0; i < n-1; i++)
        if (x[i] > 0) t = lcm(t, x[i]);

    
    int min_range, max_range;
    if (check) {
        min_range = 0;
        max_range = 86399;
    } else {
        min_range = 1;
        max_range = 86400;
    }

    if (t > max_range) {
        cout << 0 << "\n";
        return;
    }
    cout << t << '\n';

    int cur_time = t*D[0] + T[0];
    cur_time = (cur_time + mod*10000)%mod;
    cout << "cur_time: " << cur_time << '\n';
    int cur_time2 = t*D[1] + T[1];
    cur_time2 = (cur_time2 + mod*10000)%mod;
    cout << "cur_time 2: " << cur_time << '\n';

    int diff[n], g[n];
    for (int i = 1; i < n; i++) {
        diff[i] = ((D[0]%mod-D[i]%mod)+mod)%mod;
        cout << "diff: " << diff[i] << "\n";
        if (diff[i] != 0) {
            g[i] = gcd(mod, diff[i]);
            g[i] = mod/g[i];
        } else g[i] = 1;
        cout << "g: " << g[i] << "\n";
    }

    ll k = 1;
    for (int i = 1; i < n; i++) {
        k = lcm(k, g[i]);
    }

    cout << "k: " << k << '\n';
    ll times = 1;
    cout << "max_range: " << max_range << '\n';
    if (k+t <= max_range) times += (max_range-t)/k;

    cout << times << '\n';
#endif
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}