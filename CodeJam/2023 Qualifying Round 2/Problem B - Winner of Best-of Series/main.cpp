#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
#define MODULO 1000000007

int N, M;

const int MOD = 1e9 + 7;

ll powMod(ll base, int exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = (long long) res * base % MOD;
        base = (long long) base * base % MOD;
        exp >>= 1;
    }
    return res;
}

ll inverseMod(ll a) {
    return powMod(a, MOD - 2);
}

ll nChooseK(int n, int k) {
    if (k > n) return 0;
    if (k > n - k) k = n - k;
    ll result = 1;
    for (int i = 1; i <= k; i++) {
        result = (long long) result * (n - i + 1) % MOD;
        result = (long long) result * inverseMod(i) % MOD;
    }
    return result;
}

ll cal(int n, int k, ll preK) {
    if(n == k || k == 0) return 1;
    ll result = preK;
    result = (long long) result * (n - k + 1) % MOD;
    result = (long long) result * inverseMod(k) % MOD;

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        int start, end;
        if (M <= 2*N) {
            start = N;
            end = M-1;
        } else {
            start = N;
            end = 2*N-1;
        }

        ll ans = 0;
        ll sA = nChooseK(2*N-1, start);
        ll sB = nChooseK(2*M-2*N, M-(2*N-1-start));
        ll ret = (sA * sB) % MODULO;
        ans = (ans + ret) % MODULO;
        
        for(int numsA = start+1; numsA <= end; numsA++) {
            int numsB = 2*N - 1 - numsA;
            
            sA = cal(2*N-1, numsA, sA);
            sB = cal(2*M-2*N, M-numsB, sB);

            ll sol = (sA * sB) % MODULO;

            ans = (ans + sol) % MODULO;
        }

        cout << ans << '\n';

    }

    return 0;
}