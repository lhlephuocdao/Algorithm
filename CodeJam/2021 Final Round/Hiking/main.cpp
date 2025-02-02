#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstring>
#include<memory>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORE(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pb push_back
#define mp make_pair
#define sz size()
typedef long long ll;
 
const int maxn = 32;
const int MOD = 1000000000+7;
const ll MM = MOD;
 
vector<pair<int, int>> da, db;
class P3 {
  ll fact[maxn];
  int st[maxn], ed[maxn];
   
  void calc(vector<pair<int, int>>& dd, vector<int>& d) {
    int n = d.size(), nn = 1<<n;
    dd.clear();
    FOR(x,0,nn) {
      int cnt = 0;
      ll tot = 0;
      FOR(i,0,n) {
        if( ( x & (1<<i)) > 0) {
          cnt++; tot += d[i];
        }
      }
      if(tot > 1000000000)
        tot = 1000000001ll;
      dd.pb(mp(cnt, tot));
    }
  }
 
  int doit(ll i, ll j, ll cntA, ll cntB) {
    ll vA = (fact[i] * cntA) % MM;
    ll vB = (fact[j] * cntB) % MM;
    ll ret = (vA * vB) % MM;
    if(i == j) ret = (ret * 2) % MM;
    return (int) ret;
  }
   
  int find(int j, ll x) {
    int l = st[j], r = ed[j];
    if(l > r || x < 0 || x < db[l].second) return 0;
    if(x > 1000000000 || x >= db[r].second) return ed[j]-st[j]+1;
    while(l <= r) {
      int mid = (l+r)/2;
      if(db[mid].second <= x) l = mid+1;
      else r = mid-1;
    }
    return r - st[j] + 1;
  }
   
public:
   
  int solve(vector<int>& aa, vector<int>& bb, ll x, ll c, ll d) {
    int ans = 0, na = aa.size(), nb = bb.size();
    int nna = 1<<na, nnb = 1<<nb;
     
    calc(da, aa);
    calc(db, bb);
    sort(db.begin(), db.end());
 
    FOR(i,0,nb+1) {
      st[i] = nnb;
      ed[i] = -1;
    }
    FOR(i,0,nnb) { int j = db[i].first;
      st[j] = min(st[j], i);
      ed[j] = max(ed[j], i);
    //   cout << "j: " << j << "   " << st[j] << "     " << ed[j] << endl;
    }
     
    FOR(k,0,nna) {
      int i = da[k].first;
      ll dA = da[k].second;
      if(dA > d) continue;
 
      for(int j = max(0, i-1); j <= min(nb, i+1); j++) {
        //   cout << "i: " << i << "   " << "j: " << j << endl;
        ll tmp = (i+j-1); tmp *= x;
        ll lo = c - (dA + tmp), hi = d - (dA + tmp);
        //   cout << "lo: " << lo << "   " << "hi: " << hi << endl;
        if(i + j == 0 || hi < 0) continue;
        int a = find(j, hi);
        int b = find(j, lo - 1);
        int cntB = a - b;
        // cout << "a: " << a << "     b: " << b << endl;
         
        if(cntB > 0) {
          ans += doit(i, j, 1, cntB);
          ans %= MOD;
        }
      }
    }   
     
    return ans;
  }
 
  void init() {
    fact[0] = 1;
    FOR(i,1,maxn) {
      fact[i] = fact[i-1] * i;
      fact[i] %= MM;
    }
  }
 
};
 
 
int main() { 
 int t;
 scanf("%d", &t);
 P3 *inst = new P3();
   
  inst->init();
   
 while(t--) {
    int n, m;
    vector<int> aa, bb;
    int x, c, d;
    scanf("%d%d%d%d%d", &n, &m, &x, &c, &d);
    aa.resize(n); bb.resize(m);
    FOR(i,0,n) scanf("%d", &aa[i]);
    FOR(i,0,m) scanf("%d", &bb[i]);
    int ans = inst->solve(aa, bb, x, c, d);
    printf("%d\n", ans);
 }
  return 0;
}