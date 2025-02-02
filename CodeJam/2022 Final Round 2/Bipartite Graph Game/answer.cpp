#include<vector>
#include<cassert>
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
 
const int maxn = 16384, maxm = 131072;
 
int n, m, k;
int dv[maxn], dw[maxn];
int tmp_dv[maxn], tmp_dw[maxn];
int ed[maxm][2];
ll minv[maxn], minw[maxn];
   
class Sol {
   
  ll solve_once() {
    ll tot = 0;
    FOR(i,0,n) tmp_dv[i] = dv[i];
    FOR(i,0,m) tmp_dw[i] = dw[i];
    sort(tmp_dv, tmp_dv+n);
    sort(tmp_dw, tmp_dw+m);
    memset(minv, -1, sizeof(minv));
    memset(minw, -1, sizeof(minw));
    FOR(i,0,n) {
      ll v1 = i+1, v2 = tmp_dv[i];
      tot += v1*v2;
      if(minv[tmp_dv[i]] == -1) minv[tmp_dv[i]] = v1;
    }
     
    FOR(i,0,m) {
      ll v1 = i+1, v2 = tmp_dw[i];
      tot += v1*v2;
      if(minw[tmp_dw[i]] == -1) minw[tmp_dw[i]] = v1;
    }
    return tot;
  }
public:
  pair<ll,ll> solve() {
    pair<ll,ll> ans;
    ans.first = solve_once();
    ans.second = 0;
    FOR(i,0,k) {
      ll val = 0;
      val = ans.first - minv[dv[ed[i][0]]] - minw[dw[ed[i][1]]];
      ans.second = max(ans.second, val);
    }
    return ans;
  }
};
 
int main() {
    Sol* ins = new Sol();
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d", &n, &m, &k);
    memset(dv, 0, sizeof(dv));
    memset(dw, 0, sizeof(dw));
    FOR(i,0,k) {
      scanf("%d%d", &ed[i][0], &ed[i][1]);
      ed[i][0]--;
      ed[i][1]--;
      dv[ed[i][0]]++;
      dw[ed[i][1]]++;
    }
    pair<ll,ll> ans = ins->solve();
    printf("%lld %lld\n", ans.first, ans.second);
  }
    return 0;
}