#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 1000000000 + 7;
 
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

const int MOD = mod;
const int N = 1e6;
int fact[N + 5], ifact[N + 5];
 
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
    for (int i = 1; i <= N; i++)
        fact[i] = 1LL * fact[i - 1] * i % MOD;
         
    // Tính ifact[]
    ifact[0] = 1;
    ifact[N] = binpow(fact[N], MOD - 2);
    for (int i = N - 1; i >= 1; i--)
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
}
 
// Hàm tính nCk
int C(int n, int k){
    if (k > n) return 0;
    return (1LL * fact[n] * ifact[k] % MOD) * ifact[n - k] % MOD;
}

int32_t main()
{
    fastio;
    prepare();
 
    int t = 1; cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        string s; cin >> s;
        vector<int> a(n);
        int total = 0;
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
            total += a[i];
        }

        if (total % k != 0) {
            cout << 0 << '\n';
            continue;
        }

        if (total == 0) {
            // cần chọn k-1 vị trí trong n-1 vị trí
            cout << C(n-1, k-1) << '\n';
            continue;
        }

        int c = total/k;
        int cnt = 0, used = 0, zeros = 0, ans = 1;

        for (int i = 0; i < n; i++) {
            if (cnt < c) {
                cnt += a[i];
            } else if (cnt == c) {
                if (a[i] == 0)
                    zeros++;
                else {
                    // cout << "zeros: " << zeros << '\n';
                    ans *= (zeros+1);
                    ans %= mod;
                    zeros = 0;
                    cnt = 1;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}