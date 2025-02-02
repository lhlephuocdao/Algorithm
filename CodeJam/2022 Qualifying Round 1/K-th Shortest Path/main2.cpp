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
 
const int maxv = 16384;
const int ml = 4;
 
ll mult[10][10][10][10];
int p10[8];
 
class Sol {
   
  ll get_mult(int x, int y) {
    int dig[4];
    FOR(i,0,ml) {
      int dx = (x % p10[i+1]) / p10[i];
      int dy = (y % p10[i+1]) / p10[i];
      dig[i] = abs(dx-dy);
    }
    return mult[dig[0]][dig[1]][dig[2]][dig[3]];
  }
   
public:
  int solve(int ln, ll kp, int x, int y) {
    int ans[ln * 10], na = 0;
    ll rem = kp;
    ans[na++] = x;
    while(x != y) {
      set<int> cand;

      //This for loop is used to calculate the next possible candidates
      FOR(i,0,ml) {
        int dx = (x % p10[i+1]) / p10[i];
        int dy = (y % p10[i+1]) / p10[i];
        int z = x;
        if(dx < dy) z += p10[i];
        else if(dx > dy) z -= p10[i];
        printf("%d\n", z);
        if(z != x) cand.insert(z);
      }

      int next = -1;
      //This for loop is used to compare the num paths of each candidate with the K-th path
      //Decide on the next candidate if have, otherwise return -1
      FORE(it, cand) {
        ll num_paths = get_mult(*it, y);
        printf("%lld  %d\n", num_paths, *it);
        if(num_paths >= rem) {
          next = *it;
          break;
        }
        rem -= num_paths;
      }
      if(next == -1) return -1;
      x = next;
      ans[na++] = x;
    }

    char buff[128];
    sprintf(buff,"%%0%dd%%c", ln);
    FOR(i,0,na) {
      printf(buff, ans[i], i+1 == na ? '\n' : ' ');
    }

    return 0;
  }
};
 
void init() {
  p10[0] = 1;
  for(int i = 1; i < 8; i++) {
    p10[i] = p10[i-1] * 10;
  }
  memset(mult, 0, sizeof(mult));
   
  for(int a = 0; a < 10; a++) {
    for(int b = 0; b < 10; b++) {
      for(int c = 0; c < 10; c++) {
        for(int d = 0; d < 10; d++) {
          int tot = a+b+c+d;
          if(tot == 0 || tot == a || tot == b || tot == c || tot == d) mult[a][b][c][d] = 1;
          else {
            if(a > 0) mult[a][b][c][d] += mult[a-1][b][c][d];
            if(b > 0) mult[a][b][c][d] += mult[a][b-1][c][d];
            if(c > 0) mult[a][b][c][d] += mult[a][b][c-1][d];
            if(d > 0) mult[a][b][c][d] += mult[a][b][c][d-1];
          }
        }
      }
    }
  }
}
 
int main() {
  init();
 
    Sol* ins = new Sol(); 
  int t;
  scanf("%d", &t);
   
  while(t--) {
    int ln, st, ed;
    ll kp;
    scanf("%d%lld%d%d", &ln, &kp, &st, &ed);
    int ans = ins->solve(ln, kp, st, ed);
    if(ans == -1) printf("NO\n");
  }
    return 0;
}
                                                            