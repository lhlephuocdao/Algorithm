#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
 
const ll MOD = 1000000000 + 7; 
vector<pair<int, int>>  a, b;
ll fact[19];

void init()
{
    fact[0] = 1;
    for (int i = 1; i < 19; i++) {
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }
}

void calc(int* ma, vector<pair<int, int>>& a, int n, int nn)
{
    FOR(i,0,nn) {
        int cnt = 0;
        ll sum = 0;

        FOR(j,0,n) {
            if (i & (1<<j)) {
                cnt++;
                sum += ma[j];
            }
        }

        a.push_back(make_pair(cnt, sum));
    }
}

int find(int i, int d, int* st, int* end)
{
    int l = st[i], r = end[i];

    if (l > r || d < b[l].second) return 0;
    if (b[r].second <= d) return r-l+1;

    while (l <= r) {
        int mid = (l+r)/2;
        if (b[mid].second <= d) l = mid+1;
        else r = mid-1;
    }

    return r-st[i]+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    init();

    while (T--)
    {
        ll ans = 0;
        int n,m,xx,C,D;
        cin >> n >> m >> xx >> C >> D;
        int ma[n], mb[m];
        FOR(i,0,n)  cin >> ma[i];
        FOR(i,0,m)  cin >> mb[i];

        int na = 1<<n;
        int nb = 1<<m;
        a.clear();
        b.clear();
        calc(ma, a, n, na);
        calc(mb, b, m, nb);

        sort(b.begin(), b.end());
        // FORE(itr,b) cout << itr->first << " " << itr->second << '\n';
        // cout << '\n';

        int st[m+1], end[m+1];
        FOR(i,0,m+1) {
            st[i] = nb;
            end[i] = -1;
        }

        FOR(i,0,nb) {
            int x = b[i].first;
            st[x] = min(st[x], i);
            end[x] = max(end[x], i);
        }

        // FOR(i,0,m+1) cout << "i = "<< i << "  " << st[i] << "   " << end[i] << '\n';
        // FORE(itr,a) cout << itr->first << " " << itr->second << '\n';

        FOR(x,0,na)
        {
            int i = a[x].first;
            ll dA = a[x].second;
            if (dA > D) continue;

            for (int j = max(0,i-1); j <= min(m,i+1); j++) {
                // cout << "i: " << i << " j: " << j << '\n';
                ll tmp = (i + j - 1) * xx;
                ll t = tmp + a[x].second;
                // cout << "t: " << t << '\n';
                ll lo = C - t, hi = D - t;
                // cout << "lo: " << lo << "   hi: " << hi << '\n';

                if (i+j == 0 || hi < 0) continue;

                int aa = find(j, hi, st, end);
                int bb = find(j, lo-1, st, end);
                // cout << "aa: " << aa << "   bb: " << bb << '\n';

                int cnt = aa - bb;
                // cout << "cnt: " << cnt << '\n';
                if (cnt > 0) {
                    ll vA = fact[i] % MOD;
                    ll vB = (fact[j] * cnt) % MOD;
                    ll so = (vA * vB) % MOD;
                    
                    if (i == j) {
                        so *= 2;
                        so %= MOD;
                    }

                    ans += so;
                    ans %= MOD;
                }
            }
        }

        cout << ans << '\n';
    }
 
    return 0;
}