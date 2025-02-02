#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXN = 1e5 + 7;
const int MOD = 1e9 + 7;
int N, M;

 ll pow_mod(ll x, ll e) {
    if(e == 0) return 1;
    if(e == 1) return x;
    ll x2 = pow_mod(x, e/2);
    x2 = (x2 * x2) % MOD;
    if(e % 2 == 1) {
      x2 = (x2 * x) % MOD;
    }
    return x2;
  }
 
ll nCk(ll nn, ll kk) {
    if(kk < 0 || kk > nn || nn < 0) return 0;
    if(nn == kk || kk == 0) return 1;
 
    ll ans = 1;
    for(ll num = nn; num >= nn-kk+1; num--) {
      ans = (ans * num)%MOD;
    }
    for(ll num = 1; num <= kk; num++) {
      ans = (ans * pow_mod(num, MOD-2)) % MOD;
    }
    return ans;
}

ll inverseMod(ll a) {
    return pow_mod(a, MOD - 2);
}

ll cal(int n, int k, ll preK) {
    if(n == k || k == 0) return 1;
    ll result = preK;
    result = (long long) result * (n - k + 1) % MOD;
    result = (long long) result * inverseMod(k) % MOD;

    return result;
}

void solve()
{
    cin >> N >> M;
    ll ans = 0;
    int maxn = std::min(2*N-1, M-1);

    ll comA = nCk(2*N-1, N);
    ll comB = nCk(2*(M-N), M - (2*N - 1 - N));
    ans += comA*comB%MOD;
    ans %= MOD;

    for (int n = N+1; n <= maxn; n++)
    {
        int remained_m = M - (2*N - 1 - n);
        comA = cal(2*N-1, n, comA);
        comB = cal(2*(M-N), remained_m, comB);
        ans += comA*comB%MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}