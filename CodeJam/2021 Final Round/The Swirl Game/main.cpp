#include<set>
#include<map>
#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
#include<queue>
 
using namespace std;
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pb push_back
typedef long long ll;
 
const int maxn = 32;
 
int vis[maxn][maxn];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
 
class P1 {
  int n, cnt_end;
  string maxi, mini;
  char now[maxn*maxn+1];
   
  void doit(int d, int x, int y, vector<string>& dat) {
    vis[x][y] = 1;
    now[d] = dat[x][y];
    if(d+1 == n*n) {
      cnt_end++;
      if(maxi == "" || maxi < string(now)) maxi = string(now);
      if(mini == "" || mini > string(now)) mini = string(now);
      return;
    }
     
    int dist = n+1;
    FOR(k,0,4) {
      int nx = x + dx[k], ny = y + dy[k];
      int v = min(min(nx, n-1-nx), min(ny, n-1-ny));
      if(nx >= 0 && ny >=0 && nx < n && ny < n && vis[nx][ny] == 0) {
        dist = min(dist, v);
      }
    }
    FOR(k,0,4) {
      int nx = x + dx[k], ny = y + dy[k];
      int v = min(min(nx, n-1-nx), min(ny, n-1-ny));
      if(nx >= 0 && ny >=0 && nx < n && ny < n && vis[nx][ny] == 0 && dist == v) {
        vis[nx][ny] = 1;
        doit(d+1, nx, ny, dat);
        vis[nx][ny] = 0;
      }
    }
  }
   
public:
  string solve(vector<string>& dat) {
    cnt_end = 0;
    n = dat.size();
    maxi = mini = "";
    now[n*n] = 0;
     
    memset(vis, 0, sizeof(vis));
    for(int x = 0; x < n; x += max(1,n-1))
      for(int y = 0; y < n; y += max(1,n-1)) {
        vis[x][y] = 1;
        doit(0, x, y, dat);
        vis[x][y] = 0;
      }
     
    return string(maxi) + " " + string(mini);
  }
};
 
int main() { 
 int t;
 scanf("%d", &t);
 P1 *inst = new P1();
 while(t--) {
    int n;
    scanf("%d", &n);
    vector<string> dat;
    FOR(i,0,n) {
      char buff[maxn];
      scanf("%s", buff);
      dat.pb(string(buff));
    }
    printf("%s\n", inst->solve(dat).c_str());
 }
  return 0;
}