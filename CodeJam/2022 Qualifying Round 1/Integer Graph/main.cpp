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
        x /= div_s[x];
      }
    }
  }
   
public:
   
  ll solve() {
    build();

    // v[i] -> .... -> u -> ... -> 1
    // sd[u] : sum of distances from each input v[i] to node u
    // nt[u] : number of v[i] mà có đường đi từ v[1] -> 1 đi qua node u
 
    // grand : tổng shortest distance của từng node i đến tất cả n-1 node j còn lại -> duplicate
    // Do đó, D = grand / 2 (D : the sum of shortest path distances over all pairs of numbers)
    ll grand = 0, maxi = 0;
    FOR(i,0,n) {
      int x = v[i];
      ll tot = sd[x];
       
      // tot : tổng shortest distance từ node v[i] đến tất cả các node còn lại
      while(x >= 1) {
        if(x == 1) break;
        int p = x / div_s[x]; // node tiếp theo
        // cout << "x: " << x << " p: " << p << '\n';

        // v1 : số v[i] mà có đường đi đến node 1 không đi qua x
        // v2 : distance from node x to node p
        // v3 : số v[i] mà có đường đi đến node 1 đi qua x
        // v4 : tổng distance của node tiếp theo sau x
        // v5 : tổng distance của node x
        ll v1 = n - nt[x], v2 = div_s[x], v3 = nt[x], v4 = sd[p], v5 = sd[x];

        // s1 : tổng đóp góp của cạnh v2 (từ x -> p)
        ll s1 = (v1*v2), s2 = 0;

        // Khi số lượng path đi qua x < số lượng path đi qua p
        // => Tức là nt[x] paths sẽ giao với (nt[p] - nt[x]) paths tại node p
        // Do đó, ta cần tính tổng distance từ (nt[p] - nt[x]) paths đó đến node p -> s2
        // s2 = tổng distance node x - tổng distance node x - distance cạnh x-p * số paths đi qua node x
        // s2 = v4 - v5 - v2*v3
        if(nt[x] < nt[p]) {
          s2 = v4 - v5 - v2*v3;
        }

        tot += s1 + s2;
        // cout << "s1: " << s1 << " s2: " << s2 << '\n';
        x = p;
      }

      // cout << "tot: " << tot << '\n';
       
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