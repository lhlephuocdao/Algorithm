#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 1000003;
 
// directions: 0=up, 1=right, 2=down, 3=left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
 
/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug :
 *      - duplicated element
 *      - consecutive range: 1 2 3 4 5 ....
 * stress test
 */

const int MOD = 1e6 + 3;
int fact[MOD + 5], ifact[MOD + 5];
 
// Hàm lũy thừa nhanh
long long binpow(long long a, long long b) {
    long long ans = 1;
    while (b > 0){
        if (b % 2) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}
 
// Chuẩn bị
void prepare(){
    // Tính fact[]
    fact[0] = 1;
    for (int i = 1; i < MOD; i++)
        fact[i] = 1LL * fact[i - 1] * i % MOD;
         
    // Tính ifact[]
    ifact[MOD - 1] = binpow(fact[MOD - 1], MOD - 2);
    ifact[0] = 1;
    for (int i = MOD - 2; i >= 0; i--)
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
}
 
// Hàm tính nCk với n < M
int C(int n, int k){
    if (k > n) return 0;
    return (1LL * fact[n] * ifact[k] % MOD) * ifact[n - k] % MOD;
}
 
// Hàm tính nCk với n có thể lớn hơn M
int comb(long long n, long long k){
    if (k > n) return 0;
    int res = 1;
    while (n > 0){
        res = 1LL * res * C(n % MOD, k % MOD) % MOD;
        n /= MOD; k/= MOD;
    }
    return res;
}

 // tính số cách từ {x1, y1} đến {x2, y2}
int calculate(int x1, int y1, int x2, int y2) {
    int d1 = abs(x2 - x1);
    int d2 = abs(y2 - y1);
    int ret = comb(d1+d2, d1);
    return ret;
}

struct point {
    int x, y, n_snacks, n_paths;
};

int32_t main()
{
    fastio;
    prepare();
 
    int t = 1; cin >> t;
    while (t--)
    {
        int r,c,n;
        cin >> r >> c >> n;
        vector<pii> snacks(n);
        for (int i = 0; i < n; i++)
            cin >> snacks[i].fi >> snacks[i].sc;
        sort(snacks.begin(), snacks.end(), [&](pii& a, pii& b){
            if (a.fi != b.fi) return a.fi < b.fi;
            else return a.sc < b.sc;
        });

        vector<pii> res(n);
        vector<point> used;
        // push back point S
        used.push_back({1, 1, 0, 1});

        for (int i = 0; i < n; i++) {
            int x = snacks[i].first;
            int y = snacks[i].second;
            int new_snacks = 0, new_paths = 0;

            // Trong số những snacks đã checked trước đó, tìm snacks với n_snacks lớn nhất
            for (int j = 0; j < used.size(); j++) {
                if (used[j].x <= x && used[j].y <= y) {
                    if (new_snacks < used[j].n_snacks + 1) {
                        new_snacks = used[j].n_snacks + 1;
                        new_paths = used[j].n_paths * calculate(used[j].x, used[j].y, x, y) % mod;
                    } else if (new_snacks == used[j].n_snacks + 1) {
                        new_paths += used[j].n_paths * calculate(used[j].x, used[j].y, x, y) % mod;
                        new_paths %= mod;
                    }
                }
            }

            used.push_back({x, y, new_snacks, new_paths});
        }

        int ans = 0;
        int max_snacks = 0;

        for (int i = 0; i < used.size(); i++) {
            if (used[i].n_snacks > max_snacks) {
                max_snacks = used[i].n_snacks;
                ans = used[i].n_paths * calculate(used[i].x, used[i].y, r, c) % mod;
            } else if (used[i].n_snacks == max_snacks) {
                ans += used[i].n_paths * calculate(used[i].x, used[i].y, r, c) % mod;
                ans %= mod;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}