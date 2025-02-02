#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
#define int long long
#define ll long long

const int mod = 1e9 + 7;
const int maxn = 250000 + 7;
int n,m;

ll bit1[maxn], bit2[maxn];

void updatePoint(ll b[], int u, ll v) {
    int idx = u;
    while (idx <= n) {
        b[idx] += v;
        b[idx] %= mod;
        idx += (idx & -idx);
    }
}

void updateRange(int l, int r, ll v) {
    updatePoint(bit1, l, (n-l+1)*v);
    updatePoint(bit1, r+1, -(n-r)*v);
    updatePoint(bit2, l, v);
    updatePoint(bit2, r+1, -v);
}

ll getSumOnBIT(ll b[], int u) {
    int idx = u;
    ll ans = 0;
    while (idx > 0) {
        ans += b[idx];
        ans %= mod;
        idx -= (idx & -idx);
    }
    return ans;
}

ll prefixSum(int u) {
    return (getSumOnBIT(bit1, u) - getSumOnBIT(bit2, u)*(n-u)%mod + mod)%mod;
}

ll rangeSum(int l, int r) {
    return (prefixSum(r) - prefixSum(l-1) + mod) % mod;
}

int VV[250001], SS[123457], XX[123457], YY[123457];
// int S[m+1], X[m+1], Y[m+1];

void my_sol()
{
    // cin >> n >> m;
    memset(bit1, 0, sizeof(bit1));
    memset(bit2, 0, sizeof(bit2));
    for (int i = 1; i <= n; i++) {
        int v = VV[i]; //cin >> v;
        updateRange(i, i, v);
        // cout << "update i: " << i << " v: " << v << '\n';
    }

    // for (int i = 1; i <= m; i++) S[i] = SS[i]; //cin >> S[i];
    // for (int i = 1; i <= m; i++) X[i] = XX[i]; //cin >> X[i];
    // for (int i = 1; i <= m; i++) Y[i] = YY[i]; //cin >> Y[i];

    int origin = 1, flip = 0;
    // flip : 0 -> giu nguyen
    // flip : 1 -> doi chieu
    vector<ll> res;
    for (int i = 1; i <= m; i++)
    {
        if (SS[i] == 1) {
            if (flip == 0) {
                // rotate counterclockwise by X[i] -> origin increase
                origin += XX[i];
                if (origin > n) origin = origin - n;
            } else {
                // rotate clockwise by X[i] -> origin decrease
                origin -= XX[i];
                if (origin <= 0) origin = n+origin;
            }
        } else if (SS[i] == 2) {
            if (flip == 0) {
                // rotate clockwise by X[i] -> origin decrease
                origin -= XX[i];
                if (origin <= 0) origin = n+origin;
            } else {
                // rotate counterclockwise by X[i] -> origin increase
                origin += XX[i];
                if (origin > n) origin = origin - n;
            }
        } else if (SS[i] == 3) {
            flip = (flip+1)%2;
        } else if (SS[i] == 4) {
            //Increment the value in each of X[i] cells by Y[i] in clockwise order
            if (flip == 0) {
                int l = origin, r = l + XX[i] - 1;
                if (r <= n) {
                    updateRange(l, r, YY[i]);
                } else {
                    int l1 = l, r1 = n, l2 = 1, r2 = r-n;
                    updateRange(l1, r1, YY[i]);
                    updateRange(l2, r2, YY[i]);
                }
            } else {
                //Increment the value in each of X[i] cells by Y[i] in counterclockwise order
                int r = origin, l = origin-XX[i]+1;
                if (l >= 1) {
                    updateRange(l, r, YY[i]);
                } else {
                    int r1 = r, l1 = 1, r2 = n, l2 = n+l;
                    updateRange(l1, r1, YY[i]);
                    updateRange(l2, r2, YY[i]);
                }
            }
        } else if (SS[i] == 5) {
            //Compute the sum of the values in X[i] cells starting from the origin cell in clockwise order
            if (flip == 0) {
                int l = origin, r = l + XX[i] - 1;
                if (r <= n) {
                    ll ans = rangeSum(l, r);
                    res.push_back(ans%mod);
                } else {
                    int l1 = l, r1 = n, l2 = 1, r2 = r-n;
                    ll ans = rangeSum(l1, r1) + rangeSum(l2, r2);
                    res.push_back(ans%mod);
                }
            } else {
                int r = origin, l = origin-XX[i]+1;
                ll ans = 0;
                if (l >= 1) {
                    ans = rangeSum(l, r);
                } else {
                    int r1 = r, l1 = 1, r2 = n, l2 = n+l;
                    ans = rangeSum(l1, r1) + rangeSum(l2, r2);
                }
                res.push_back(ans%mod);
            }
        }
    }

    for (auto x : res) cout << x << " ";
    cout << '\n';
}

void my_code()
{
    int t = 10;
    while (t--) my_sol();
}

long long generate_random_int(long long min, long long max) {
    return min + (rand() % (long long)(max - min + 1));
}

void stress_test(long long size, long long min, long long max) {
    int idx = 1;
    while(1) {
        
        n = 250000;
        m = 123456;
        for (int i = 1; i <= n; i++)
            VV[i] = generate_random_int(1, 1e9);
        for (int i = 1; i<= m; i++)
            SS[i] = generate_random_int(1, 5);
        for (int i = 1; i<= m; i++)
            XX[i] = generate_random_int(1, n);
        for (int i = 1; i<= m; i++)
            YY[i] = generate_random_int(1, 1e9);


        auto start = high_resolution_clock::now();
        cout << "Iteration: " << idx << "\n";
        my_code();
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "run time: " << duration.count() << '\n';

        if (duration.count() > 2000) break;

        cout << "PASS\n";
        ++idx;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("out.txt", "w", stdout);
    srand(time(0));
    stress_test(100000, 1, 10000000000000);
    return 0;
}