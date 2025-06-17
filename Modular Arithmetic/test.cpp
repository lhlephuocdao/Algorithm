#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long

const int mod = 86400;

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

int solve1(int nn, vector<int> time, vector<int> dif)
{
    int n = nn;
    int T[n], D[n];
    bool check = true, check2 = true;
    for (int i = 0; i < n; i++)
    {
        T[i] = time[i];
        if (check && i > 0 && T[i] != T[i-1]) check = false;
    }

    for (int i = 0; i < n; i++) {
        D[i] = dif[i];
        if (check2 && i > 0 && (D[i]%mod) != (D[i-1]%mod)) check2 = false;
    }

    if (check && check2) {
        return 86400;
    }

    int x[n];
    for (int i = 1; i < n; i++) {
        int DD = ((D[0]%mod-D[i]%mod)%mod + mod)%mod;
        int TT = (T[i] - T[0] + mod) % mod;
        int G = gcd(DD, mod);
        if (TT % G != 0) {
            return 0;
        }

        if (DD == 0) {
            if (TT != 0) {
                return 0;
            } else {
                x[i-1] = -1;
                continue;
            }
        }

        int t = TT/G, d = DD/G, m = mod/G;
        int inverse_d = exp(d, phi(m)-1, m);

        x[i-1] = (t*inverse_d + m)%m;
    }

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

    if (t > max_range) return 0;

    int diff[n], g[n];
    for (int i = 1; i < n; i++) {
        diff[i] = ((D[0]%mod-D[i]%mod)+mod)%mod;
        if (diff[i] != 0) {
            g[i] = gcd(mod, diff[i]);
            g[i] = mod/g[i];
        } else g[i] = 1;
    }

    ll k = 1;
    for (int i = 1; i < n; i++) {
        k = lcm(k, g[i]);
    }

    ll times = 1;
    if (k+t <= max_range) times += (max_range-t)/k;

    return times;
}
/* ================================================== */

#define M           (24*60*60)
 
int mpow(int x, int y, int m) {
        if (y == 0) return 1;
        if (y == 1) return x;
        long long ans = mpow(x, y / 2, m);
        ans = (ans * ans) % m;
        if (y & 1)
                ans = (ans * x) % m;
        return ans;
}
 
int minv(int a, int m) {
        return mpow(a, phi(m) - 1, m);
}
 
int solve3(vector<pair<int,int> > &line) {
        vector<int> X(M + 1, -1), cnt(M + 1);
        int n = line.size();
        /* first step */
        for (int i = 1; i < n; ++i) {
                int A = ((((line[i].first%M) - (line[0].first%M)) % M) + M) % M;
                int B = (line[0].second - line[i].second + M) % M;
                int G = gcd(A, M);
                if (B % G != 0)
                        return 0;
 
                int a = A / G, b = B / G, m = M / G;
                int x = ((long long)b * minv(a, m)) % m;
                if (X[m] >= 0 && X[m] != x)
                        return 0;
 
                X[m] = x;
                ++cnt[m];
        }
 
        /* second step */
        int ans = 0;
        vector<int> total(M + 1);
        for (int m = 1; m <= M; ++m) {
                if (X[m] < 0)
                        continue;
                for (int x = X[m]; x < M; x += m) {
                        total[x] += cnt[m];
                        if (total[x] + 1 == n)
                                ++ans;
                }
        }
        return ans;
}

int solve2(int nn, vector<int> time, vector<int> dif)
{
                int n = nn;
                vector<pair<int,int> > line(n);
                for (int i = 0; i < n; ++i) {
                        // string s;
                        // cin >> s;
                        line[i].second = time[i];
                }
                for (int i = 0; i < n; ++i)
                        line[i].first = dif[i];
                return solve3(line);
}

/* ================================================== */
void show(const vector<int>& v) {
    long long n = v.size();
    for(long long i = 0; i < n; ++i) {
        std::cout << v[i] <<" ";
    }
    cout << "\n";
}
long long generate_random_int(long long min, long long max) {
    return min + (rand() % (long long)(max - min + 1));
}

void stress_test(long long size, long long min, long long max) {
    int i = 1;
    int MAX = 1e9;
    while(1) {
        cout << "Iteration: " << i << "\n";
        long long n = generate_random_int(2, 3);
        vector<long long> times, dif;
        for(long long i = 0; i < n; ++i) {
            long long time = generate_random_int(0, 86400);
            times.push_back(time);

            ll d = generate_random_int(-10000, 10000);
            dif.push_back(d);
        }
        long long my_ans = solve1(n, times, dif);
        long long refer_ans = solve2(n, times, dif);
        if(my_ans != refer_ans) {
            cout << "Fail: failed not less case\n";
            cout << "n = " << n << '\n';
            show(times);
            show(dif);
            cout << "Expected: " << refer_ans << "\n";
            cout << "ACTUAL: " << my_ans << "\n";
            break;
        }
        cout << "PASS\n";
        ++i;
    }
}
 
signed main() {
    srand(time(0));
    stress_test(100000, 1, 10000000000000);
    return 0;
}