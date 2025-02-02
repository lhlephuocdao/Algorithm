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
 
const int maxr = 128, maxn = 16;
const int MOD = 1000000000+7;
 
const int S = 0, R = 1, B = 2;
// S R B
int r, c, n;
int sum[4][maxr][maxr];
int pref[maxn];
bool verbose = false;
int dp[maxr][maxr][maxn];
 
class Sol {
     
  bool satisfied(int p, int x1, int y1, int x2, int y2) {
    int t = pref[p];
    int cnt = sum[t][x2][y2] + sum[t][x1-1][y1-1] - sum[t][x1-1][y2] - sum[t][x2][y1-1];
    return cnt >= 1;
  }
   
  int doit(int x, int y, int k) {
    if(x > r || y > c) return 0;
    int ret = dp[x][y][k];
    if(ret != -1) return ret;
 
    if(k == n-1) {
      ret = satisfied(k, x, y, r, c) ? 1 : 0;
      return dp[x][y][k] = ret;
    }
     
    ret = 0;
    FOR(i,x,r) {
      if(!satisfied(k, x, y, i, c)) continue;
      ret += doit(i+1, y, k+1);
      ret %= MOD;
    }
     
    FOR(j,y,c) {
      if(!satisfied(k, x, y, r, j)) continue;
      ret += doit(x, j+1, k+1);
      ret %= MOD;
    }
     
    return dp[x][y][k] = ret;
  }
   
  public:
  int solve() {
     
    FOR(k,0,3) {
      FOR(i,1,r+1) {
        FOR(j,1,c+1) {
          sum[k][i][j] += sum[k][i-1][j];
          sum[k][i][j] += sum[k][i][j-1];
          sum[k][i][j] -= sum[k][i-1][j-1];
        }
      }
    }
    memset(dp, -1, sizeof(dp));
    return doit(1, 1, 0);
  }
};
 
int main() {
    Sol* ins = new Sol();
  int t;
  scanf("%d", &t);
 
  char buff[1024];
  while(t--) {
    scanf("%d%d%d", &r, &c, &n);
     
    memset(sum, 0, sizeof(sum));
    FOR(i,1,r+1) {
      scanf("%s", buff);
      FOR(j,1,c+1) {
        int cell = -1;
        if(buff[j-1] == 'S') cell = S;
        else if(buff[j-1] == 'R') cell = R;
        else if(buff[j-1] == 'B') cell = B;
        if(cell != -1) {
          sum[cell][i][j] = 1;
        }
      }
    }
     
    memset(pref, 0, sizeof(pref));
    scanf("%s", buff);
    FOR(i,0,n) {
      if(buff[i] == 'S') pref[i] = S;
      else if(buff[i] == 'R') pref[i] = R;
      else if(buff[i] == 'B') pref[i] = B;
    }
       
    int ans = ins->solve();
    printf("%d\n", ans);
  }
    return 0;
}