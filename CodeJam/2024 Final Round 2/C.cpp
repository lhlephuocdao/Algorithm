#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 444449;
const int MOD = 444449;

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

int32_t main()
{
    fastio;
    prepare();

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,v, root = -1;
        cin >> n >> v;
        vector<int> a(n), l(n), r(n), par(n, -1);
        for (auto& x : a) cin >> x;
        for (auto& x : l) cin >> x, x--;
        for (auto& x : r) cin >> x, x--;

        for (int i = 0; i < n; i++) {
            if (l[i] != -1) par[l[i]] = i;
            if (r[i] != -1) par[r[i]] = i;
        }

        for (int i = 0; i < n; i++)
            if (par[i] == -1) {
                root = i;
                break;
            }

        vector<int> inorder;
        function<void(int)> dfs = [&](int u){
            if (l[u] != -1) dfs(l[u]);
            inorder.push_back(u);
            if (r[u] != -1) dfs(r[u]);
        };
        dfs(root);
        assert(inorder.size() == n);

        // add thêm node n có fixed x-coordinate là v+1
        inorder.push_back(n);
        a.push_back(v+1);

        int x = 0, cnt = 0;
        int ans = 1;
        for (int i = 0; i <= n; i++) {
            if (a[inorder[i]] == 0) {
                cnt++;
            } else {
                int k = a[inorder[i]] - x - 1;
                if (k < cnt) {
                    ans = 0;
                    break;
                }
                ans *= comb(k, cnt);
                ans %= mod;
                cnt = 0;
                x = a[inorder[i]];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}