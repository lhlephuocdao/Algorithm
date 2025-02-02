#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;
const int maxn = 1e6 + 7;
int n, k, a[maxn];

int fact[maxn + 5], ifact[maxn + 5];
 
// Hàm lũy thừa nhanh
ll binpow(ll a, ll b) {
    ll ans = 1;
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
    for (int i = 1; i <= maxn; i++)
        fact[i] = 1LL * fact[i - 1] * i % MOD;
         
    // Tính ifact[]
    ifact[0] = 1;
    ifact[maxn] = binpow(fact[maxn], MOD - 2);
    for (int i = maxn - 1; i >= 1; i--)
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
}
 
// Hàm tính nCk
ll Cnk(int n, int k){
    if (k > n) return 0;
    return (1LL * fact[n] * ifact[k] % MOD) * ifact[n - k] % MOD;
}

void solve()
{
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    int total = 0;
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        a[i] = s[i]-'0';
        if (a[i] == 1) total++;
    }

    if (total == 0) {
        cout << Cnk(n-1, k-1) << '\n';
        return;
    }

    if (k == 1) {
        cout << 1 << '\n';
        return;
    }

    if (total % k != 0) {
        cout << 0 << '\n';
        return;
    }

    int need = total/k;
    ll ans = 1;
    int count_one = 0, count_zero = 0;
    bool calc = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            count_one++;
            if (calc) {
                ans *= 1ll*(count_zero+1);
                ans %= MOD;

                calc = false;
                count_zero = 0;
            }
        }
        else if (a[i] == 0 && calc == true) {
            count_zero++;
        }

        if (count_one == need) {
            count_one = 0;
            calc = true;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    prepare();
    while(t--) solve();

    return 0;
}