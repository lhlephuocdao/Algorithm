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
 
const int maxn = 65536, maxm = 262144;
const ll MOD = 1000000007;
 
class Sol {
  int n, m;
  vector<int> cnt;
   
public:
  pair<ll,ll> solve(vector<int>& val, vector<int>& diff) {
    ll ans_max = 0, cnt_ans = 1;
    n = val.size();
    sort(val.begin(), val.end());
    int now = 0;
    cnt.resize(n);
    FOR(i,0,n) {
      now += diff[i];
      cnt[i] = now;
    }
    sort(cnt.begin(), cnt.end());
     
    int prev = -1, cnt_contig = 0;
    for(int i = n-1; i >= 0; i--) {
      ll v1 = cnt[i], v2 = val[i];
      ans_max += v1*v2;
      if(prev != cnt[i]) {
        cnt_contig = 1;
        prev = cnt[i];
      }
      else cnt_contig++;
      cnt_ans *= cnt_contig;
      cnt_ans %= MOD;
    }
    return make_pair(ans_max, cnt_ans);
  }
};
 
int main() {
 
    Sol* ins = new Sol(); 
  int t;
  scanf("%d", &t);
   
  while(t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> val = vector<int>(n, 0), diff = vector<int>(n+1, 0);
    FOR(i,0,n) scanf("%d", &val[i]);
    FOR(i,0,m) {
      int st, ed;
      scanf("%d%d", &st, &ed);
      diff[st-1]++;
      diff[ed]--;
    }
    pair<ll,ll> ans = ins->solve(val, diff);
    printf("%lld %lld\n", ans.first, ans.second);
  }
    return 0;
}