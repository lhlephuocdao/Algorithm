#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<vector<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<set<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<int>& a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

void debug(map<int, vector<int>>& m)
{
    for (auto v : m) {
        cout << v.first << " : ";
        for (auto x : v.second)
            cout << x << ' ';
        cout << '\n';
    }
}

const int MOD = 998244353;
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
    ifact[N] = binpow(fact[N], MOD - 2);
    for (int i = N - 1; i >= 1; i--)
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
}

// Hàm tính nCk
int C(int n, int k){
    if (k > n) return 0;
    if (k == n) return 1;
    return (1LL * fact[n] * ifact[k] % MOD) * ifact[n - k] % MOD;
}

int32_t main()
{
    fastio;

    const int mod = 998244353;
    int t = 1;
    cin >> t;

    prepare();

    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        vector<int> num2(n, 0);
        for (int i = 1; i < n; i++)
            if (a[i] == 2)
                num2[i] = num2[i-1] + 1;
            else
                num2[i] = num2[i-1];

        // debug(num2);
        int f1 = -1,l3 = -1;
        for (int i = 0; i < n; i++)
            if (a[i] == 1) {
                f1 = i;
                break;
            }

        for (int i = n-1; i >= 0; i--)
            if (a[i] == 3) {
                l3 = i;
                break;
            }

        // cout << "f1: " << f1 << " l3: " << l3 << '\n';

        if (f1 == -1 || l3 == -1) {
            cout << 0 << '\n';
            continue;
        }

        int ans = 0;
        for (int i = f1; i < l3; i++)
        {
            if (a[i] == 1) {
                int n2 = num2[l3-1] - num2[i];
                // cout << "i: " << i << " n2: " << n2 << '\n';
                for (int k = 1; k <= n2; k++)
                {
                    ans += C(n2, k) % MOD;
                    // cout << "C " << n2 << "," << k << " : " << C(n2, k) << '\n';
                    ans %= MOD;
                    // cout << "ans: " << ans << '\n';
                }
            }
        }

        for (int i = l3-1; i > f1; i--)
        {
            if (a[i] == 3)
            {
                int n2 = num2[i] - num2[f1];
                // cout << "i: " << i << " n2: " << n2 << '\n';
                for (int k = 1; k <= n2; k++)
                {
                    ans += C(n2, k) % MOD;
                    // cout << "C " << n2 << "," << k << " : " << C(n2, k) << '\n';
                    // cout << "ans: " << ans << '\n';
                    ans %= MOD;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}