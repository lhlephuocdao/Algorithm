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
 
const int maxn = 32, maxnn = 262144;
int n, m, k;
int x[maxn], y[maxn];
int nn, mm, a[maxnn], b[maxnn];
 
class Sol {
  void calc(int n0, int* v, int& n1, int* vv) {
    int lim = 1<<n0;
    n1 = 0;
    FOR(tt,1,lim) {
      int cnt = 0, tot = 0;
      FOR(i,0,n0) {
        if((tt & (1<<i))) {
          cnt++;
          tot += v[i];
          if(cnt > k) break;
        }
      }
      if(cnt == k) {
        vv[n1++] = tot;
      }
    }
  }
   
public:
  pair<int, int> solve() {
    pair<int, int> ans;
    calc(n, x, nn, a);
    calc(m, y, mm, b);
    sort(a, a+nn);
    sort(b, b+mm);
    ans.first = abs(a[0] - b[0]);
    ans.second = max(abs(a[0] - b[mm-1]), abs(b[0] - a[nn-1]));
    int i = 0, j = 0;
    while(i < nn && j < mm && ans.first > 0) {
      ans.first = min(ans.first, abs(a[i] - b[j]));
      if(a[i] > b[j]) j++;
      else i++;
    }
     
    return ans;
  }
};
 
int main() {
    Sol* ins = new Sol(); 
  int t;
  scanf("%d", &t);
   
  while(t--) {
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,0,n) scanf("%d", &x[i]);
    FOR(i,0,m) scanf("%d", &y[i]);
    pair<int, int> ans = ins->solve();
    printf("%d %d\n", ans.first, ans.second);
  }
    return 0;
}