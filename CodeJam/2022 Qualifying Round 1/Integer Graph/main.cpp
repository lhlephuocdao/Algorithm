#include<cassert>
#include<vector>
#include<cstdio>
#include<map>
#include<set>
#include<cstring>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
#include<iostream>
#include<queue>
using namespace std;
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pb push_back
typedef long long ll;
 
const int maxn = 524288, maxv=1048576;
 
int n, v[maxn], nt[maxv], div_s[maxv];
ll sd[maxv];
 
class Sol {
  void build() {
    memset(sd, 0, sizeof(sd));
    memset(nt, 0, sizeof(nt));
    FOR(i,0,n) {
      int x = v[i];
      ll d = 0;
      while(x >= 1) {
        nt[x]++;
        sd[x] += d;
        if(x == 1) break;
        d += div_s[x];
        int p = x / div_s[x];
        x = p;
      }
    }
  }
   
public:
   
  ll solve() {
    build();

    for (int i = 0; i < 30; i++)
      cout << sd[i] << " ";
    cout << '\n';

    for (int i = 0; i < 30; i++)
      cout << nt[i] << " ";
    cout << '\n';
 
    ll grand = 0, maxi = 0;
    FOR(i,0,n) {
      int x = v[i];
      ll tot = 0;
      tot = (tot + sd[x]);
       
      while(x >= 1) {
        if(x == 1) break;
        int p = x / div_s[x];
        ll v1 = n - nt[x], v2 = div_s[x], v3 = nt[x], v4 = sd[p], v5 = sd[x];
        ll s1 = (v1*v2), s2 = 0;
        if(nt[x] != nt[p]) {
          s2 = v4 - (v5 + (v2 * v3));
        }
        tot = (tot + s1 + s2);
        cout << "x: " << x << "   " << tot << '\n';
        x = p;
      }
       
      maxi = max(maxi, tot);
      grand += tot;
    }
    return grand/2 - maxi;
  }
   
  void init() {
    memset(div_s, 0, sizeof(div_s));
    div_s[1] = 1;
    for(int x = 2; x <= 1000*1000; x++) {
      if(div_s[x] == 0) {
        for(int y = x; y <= 1000*1000; y += x) {
          if(div_s[y] == 0)
            div_s[y] = x;
        }
      }
    }
  }
};
 
int main() {
 Sol* ins = new Sol();
  int t;
  scanf("%d", &t);
  ins->init();
  while(t--) {
    scanf("%d", &n);
     
    FOR(i,0,n) scanf("%d", &v[i]);
 
    ll ans =  ins->solve();
    printf("%lld\n", ans);
  }
   
 return 0;
}