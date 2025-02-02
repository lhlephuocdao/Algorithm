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
 
const int maxn = 8;
 
int n, aa, bb, ans = 0;
int dig[10];
 
class Sol {
  int rev(int x) {
    int ret = 0;
    while(x > 0) {
      ret = ret*10 + x % 10;
      x/=10;
    }
    return ret;
  }
   
  void brute(int rem, int num){
    if(num >= aa) return;
    ans = max(ans, num);
    if(rem == 0) 
    {
        // cout << ans << endl;
        return;
    }
    FOR(i,1,10) {
      if(dig[i] > 0) {
        dig[i]--;
        brute(rem-1, num*10 + i);
        dig[i]++;
      }
    }
  }
   
  public:
 
  int solve() {
    int rev_aa = rev(aa);
    aa = min(rev_aa, aa);
     
    {
      int rem_bb = bb;
      FOR(i,0,10) dig[i] = 0;
      while(rem_bb > 0) {
        dig[rem_bb%10]++;
        rem_bb/=10;
      }
    //   FOR(i,0,10) cout << dig[i] << endl;
    }
     
    ans = 0;
    FOR(i,1,10) {
      if(dig[i] > 0) {
        dig[i]--;
        brute(n-1, i);
        dig[i]++;
      }
    }
    return ans;
  }
};
 
int main() {
 Sol* ins = new Sol(); 
  int t;
  scanf("%d", &t);
   
  while(t--) {
    scanf("%d%d%d", &n, &aa, &bb);
    int ans = ins->solve();
    printf("%d\n", ans);
  }
 return 0;
}