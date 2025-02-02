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
// typedef long long ll;
 
const int MOD = 1000000000 + 7;
const int maxR = 1024, maxC = 16, maxK = 1024;
int R, C, K;
int init[maxC], arr[maxR][maxC], stat_a[maxR];
int colCnt[maxC];
char buff[maxC+1];
 
int dp[maxR][1<<maxC];
int nc, cand[1<<maxC];
int nrc, rcand[1<<maxC];
class Sol {
  bool valid(int y) {
    while(y > 0) {
      if( (y&1) == 1) {
        if( (y&2) == 0) return false;
        y /= 2;
      }
      y /= 2;
    }
    return true;
  }
public:
  int solve() {
    int stat_i = 0;
    FOR(i,0,C) if(init[i]) stat_i += 1<<i;
     
    FOR(i,0,R) {
      stat_a[i] = 0;
      FOR(j,0,C)
        if(arr[i][j])
          stat_a[i] += 1<<j;
    }
    const int cc = 1<<C;
    memset(dp, 0, sizeof(dp));
    dp[0][stat_i] = 1;
     
    nc = 0;
    FOR(y,0,cc) {
      if(!valid(y)) continue;
      cand[nc++] = y;
    }   
     
     
    FOR(i,0,R) {
      nrc = 0;
      FOR(j,0,nc) {
        int y = cand[j];
        if( (stat_a[i] & y) > 0) continue;
        rcand[nrc++] = y;
      }
       
      FOR(x,0,cc) {
        if(dp[i][x] == 0) continue;
        FOR(j,0,nrc) {
          int y = rcand[j];
          // assert(valid(y) && (stat_a[i] & y) == 0);
          int row = stat_a[i] | y;
          int result = x ^ row;
          dp[i+1][result] += dp[i][x];
          dp[i+1][result] %= MOD;
        }
      }
    }
         
    return dp[R][0];
  }
};
 
int main() {
    Sol* ins = new Sol();
  int t;
  scanf("%d", &t);
 
  while(t--) {
    scanf("%d%d%d", &R, &C, &K);
    scanf("%s", buff);
    assert(strlen(buff) == C);
    FOR(i,0,C) if(buff[i] == '+') init[i] = 0; else init[i] = 1;
    memset(arr, 0, sizeof(arr));
    FOR(i,0,K) {
      int r,c;
      scanf("%d%d", &r, &c);
      arr[r-1][c-1] = 1;
    }
    int ans = ins->solve();
    printf("%d\n", ans);
  }
   
   
    return 0;
}