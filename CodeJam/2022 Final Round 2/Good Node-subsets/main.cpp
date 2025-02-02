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
 
const int maxn = 131072;
int n, root;
int v[maxn], pare[maxn];
vector<int> ch[maxn];
 
ll in[maxn], ex[maxn];
class Sol {
   
  void doit(int x) {
    if(ch[x].size() == 0) { // leaf
      ex[x] = 0;
      in[x] = v[x];
      return;
    }
    ll tot = 0, maxv;
    in[x] = v[x];
    for(int i = 0; i < ch[x].size(); i++) {
      int y = ch[x][i];
      doit(y);
      tot += max(in[y], ex[y]);
      ll diff = in[y] - max(in[y], ex[y]);
      if(i == 0) maxv = diff;
      else maxv = max(maxv, diff);
      in[x] += ex[y];
    }
    ex[x] = tot + maxv;
  }
   
public:
  ll solve() {
    doit(root);
    return max(in[root], ex[root]);
  }
};
 
int main() {
    Sol* ins = new Sol();
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    FOR(i,0,n) {
      scanf("%d", &v[i]);
      ch[i].clear();
    }
    FOR(i,0,n) {
      scanf("%d", &pare[i]);
      pare[i]--;
      if(pare[i] != -1) {
        ch[pare[i]].push_back(i);
      } else
        root = i;
    }
    ll ans = ins->solve();
    printf("%lld\n", ans);
  }
    return 0;
}