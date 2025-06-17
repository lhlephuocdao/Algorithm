#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)

const int maxn = 2e5 + 7;
const int MAX = 1e9;
int n,k;
ll ans = 0;

struct point {
    int l;
    int r;
} p[maxn];

void calc(int n0) {
   ull lim = 1<<n0;

   FOR(tt,1,lim) {
        int cnt = 0, l = - MAX, r = MAX;
        FOR(i,0,n0) {
            if((tt & (1<<i))) {
                cnt++;
                l = (p[i].l >= l) ? p[i].l : l;
                r = (p[i].r <= r) ? p[i].r : r;
                if(cnt > k) break;
            }
        }
        if(cnt == k && l <= r) {
            ans += r-l+1;
            ans %= MOD;
        }
   }
}

void cal(int l, int r, int k, int index)
{
    if (l > r) return;

    if (k == 0) {
        ans += r-l+1;
        ans %= MOD;
        return;
    }

    for (int i = index; i <= n; i++) {
        point c = p[i];
        int new_l = (c.l >= l) ? c.l : l;
        int new_r = (c.r <= r) ? c.r : r;
        cal(new_l, new_r, k-1, i+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> p[i].l >> p[i].r;

    // cal(-MAX, MAX, k, 1);
    calc(n);

    cout << ans << '\n';

    return 0;
}