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
 
const ll INF = 10000000000000ll;
const int maxn = 1048576;
int n, to[maxn];
 
class Sol {
  int vis[maxn];
  vector<int> cc_all;
  int m, cc[maxn], cnt[maxn];
   
  ll init_p, ans;
 
  ll gcd(ll x, ll y) {
    while(y > 0) {
      ll z = x % y;
      x = y;
      y = z;
    }
    return x;
  }
   
  void find_cc() {
    memset(vis, 0, sizeof(vis));
    cc_all.clear();
    FOR(i,0,n) {
      if(vis[i]) continue;
      int now = i, sz = 0;
      while(!vis[now]) {
        vis[now] = 1;
        sz++;
        now = to[now];
      }
      cc_all.push_back(sz);
    }
    sort(cc_all.begin(), cc_all.end());
    // FORE(it, cc_all) printf("%d ", *it); printf("\n");
    int nc = cc_all.size();
    memset(cc, 0, sizeof(cc));
    memset(cnt, 0, sizeof(cnt));
    m = 0;
    FOR(i,0,nc) {
      cnt[m]++;
      if(i+1 == nc || cc_all[i+1] != cc_all[i]) {
        cc[m] = cc_all[i];
        m++;
      }
    }
    // printf("m = %d: ", m );
    // FOR(i,0,m) printf("%d (x %d) ", cc[i], cnt[i]);
    // printf("\n");
    init_p = 1;
    FOR(i,0,m) {
      ll g = gcd(init_p, cc[i]);
      init_p *= cc[i] / g;
    }
  }
   
  ll lcm(ll x, ll y) {
    ll g = gcd(x, y);
    y /= g;
    return x * y;
  }
   
  ll lcm3(ll x, ll y, ll z) {
    ll xy = lcm(x, y);
    return lcm(xy, z);
  }
 
  ll lcm_left[maxn], lcm_right[maxn];
 
  void pick_one() {
    FOR(i,0,m) {
      if(i == 0) lcm_left[i] = cc[i];
      else {
        ll g = gcd(lcm_left[i-1], cc[i]);
        lcm_left[i] = (cc[i]/g) * lcm_left[i-1];
      }
    }
    for(int i = m-1; i >= 0; i--) {
      if(i == m-1) lcm_right[i] = cc[i];
      else {
        ll g = gcd(lcm_right[i+1], cc[i]);
        lcm_right[i] = (cc[i]/g) * lcm_right[i+1];
      }
    }
    FOR(i,0,m) {
      ll vL = i == 0 ? 1ll : lcm_left[i-1];
      ll vR = i+1 == m ? 1ll : lcm_right[i+1];
      ll next = lcm(vL, vR); // <= init.
 
      if(cnt[i] >= 2) { // get cc[i] * 2
        ll val = next;
        val = lcm(val, cc[i]);
        ans = min(ans, val);
      }
 
      for(int k = 1; k < cc[i] && k <= cc[i] - k; k++) {
        ll val = next;
        if(cnt[i] > 1) val = lcm(val, cc[i]);
        val = lcm(val, k);
        if(val <= INF) {
          val = lcm(val, cc[i] - k);
          ans = min(val, ans);
        }
      }
    }
  }
   
  void pick_two() {
     
    FOR(i,0,m) {
      ll vL = i == 0 ? 1 : lcm_left[i-1];
      ll vM = 1;
      if(cnt[i] >= 2) vL = lcm(vL, cc[i]);
      FOR(j,i+1,m) {
        ll vR = j+1 == m ? 1 : lcm_right[j+1];
        if(cnt[j] >= 2) vR = lcm(vR, cc[j]);
 
        ll val = lcm3(vL, vM, vR);
        val = lcm(val, cc[i] + cc[j]);
        if(ans > val) {
          ans = val;
          // printf("ans = %lld: L (%lld) R (%lld) [%d +%d -> %d]\n",
          // ans, vL, vR, cc[i], cc[j], cc[i] + cc[j]);
        }
         
        vM = lcm(vM, cc[j]);
      }
    }
  }
   
public:
  pair<ll, ll> solve() {
    find_cc();
    ans = init_p;
     
    pick_one();
    pick_two();
     
    return make_pair(init_p, ans);
  }
};
 
int main() {
    Sol* ins = new Sol();
  int t;
  scanf("%d", &t);
 
  while(t--) {
    scanf("%d", &n);
    FOR(i,0,n) {
      scanf("%d", &to[i]);
      to[i]--;
    }
 
    pair<ll, ll> ans = ins->solve();
    assert(ans.first >= ans.second && ans.second >= 1ll);
    printf("%lld %lld\n", ans.first, ans.second);
  }
    return 0;
}