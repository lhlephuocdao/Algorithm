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
 
const int maxn = 131072;
 
char label[maxn];
int pare[maxn], len[maxn], cnt[maxn];
int n;
 
vector<int> ch[maxn];
 
class Sol {
  int maxd = -1, ans = 0;
   
  void dfs(int x, int dep) {
    len[x] = 1; cnt[x] = 1;
 
    int max1 = -1, max2 = -1;
     
    FORE(it, ch[x]) {
      int y = *it;
       
      dfs(y, dep+1);
       
      if(len[x] < len[y] + 1) {
        len[x] = len[y] + 1;
        cnt[x] = cnt[y];
      } else if(len[x] == len[y] + 1) {
        cnt[x] += cnt[y];
      }
       
      if(len[y] > max1) {
        max2 = max1;
        max1 = len[y];
      } else {
        max2 = max(max2, len[y]);
      }
    }
     
    if(max2 == -1) { // leaf or single child
      if(maxd < len[x]) {
        maxd = len[x];
        ans = cnt[x];
      } else if(maxd == len[x]) {
        ans += cnt[x];
      }
      return;
    }   
     
    int cur_max = max1 + max2 + 1, cur_cnt = 0;
 
    if(cur_max < maxd) return;
     
    if(max1 == max2) {
      int tot = 0, sum_sq = 0;
      FORE(it, ch[x]) {
        int y = *it;
        if(len[y] == max1) {
          tot += cnt[y];
          sum_sq += cnt[y]*cnt[y];
        }
      }
      cur_cnt = (tot*tot - sum_sq) / 2;
    } else {
      int tot1 = 0, tot2 = 0;
      FORE(it, ch[x]) {
        int y = *it;
        if(len[y] == max1) tot1 = cnt[y];
        else if(len[y] == max2) {
          tot2 += cnt[y];
        }
      }
      cur_cnt = tot1 * tot2;
    }

    if(cur_max > maxd) {
      maxd = cur_max;
      ans = cur_cnt;
    } else if(cur_max == maxd) {
      ans += cur_cnt;
    }   
  }
   
public:
  pair<int, int> solve() {
    FOR(i,0,n) ch[i].clear();
         
    FOR(i,0,n) {
      if(pare[i] != -1 && label[i] == label[pare[i]])
        pare[i] = -1;
       
      if(pare[i] == -1) continue;
       
      ch[pare[i]].pb(i);
    }
     
    maxd = -1;
    FOR(i,0,n)
      if(pare[i] == -1)
        dfs(i, 0);
     
    return make_pair(maxd, ans);
  }
};
 
int main() {
    Sol* ins = new Sol();
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    scanf("%s", label);
    FOR(i,0,n) {
      scanf("%d", &pare[i]);
      pare[i]--;
    }
    pair<int,int> ans = ins->solve();
    printf("%d %d\n", ans.first, ans.second);
  }
    return 0;
}