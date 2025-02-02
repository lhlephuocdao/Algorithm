#include <bits/stdc++.h>
 
using namespace std;
 
#define N 100000 
 
int a[N+10],v[N+10],p[N],tot;  
 
void init() {
	for (int i = 2; i <= N; i++) {
		if (!v[i]) p[++tot] = i;
		for (int j = 1; j <= tot; j++) {
			if (i*p[j]>N) break;
			v[i*p[j]] = 1;
			if (i%p[j]==0) break;
		}
	}
}
 
map<vector<pair<int,int> >,int> f;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	init();
		int n,k,d;
		cin >> n >> k;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			int t;
			cin >> t;
			vector<pair<int,int> > g,rg;
			for (int j = 1; j <= tot && t != 1; j++) 
			 if (t%p[j] == 0) {
			 	int cnt = 1;
			 	t /= p[j];
				while(t%p[j] == 0) {
					cnt++;
					t /= p[j];
				} 
				cnt %= k;
				if(cnt) {
				   g.push_back({p[j],cnt});
				   rg.push_back({p[j],k-cnt});
				}
			}
			ans += f[rg];
			f[g]++;
		}
		cout << ans << "\n";
    return 0;
}