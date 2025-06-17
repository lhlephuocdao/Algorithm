#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	while (b) b^=a^=b^=a%=b;
	return a;
}

void solve(){
	int n;
	cin>>n;

	int a[n+1];
	for (int i=1; i<=n; i++) cin>>a[i];

	int ans[n+1];
	for (int i=1; i<=n; i++) ans[i]=0;

	vector <pair <int,int> > f;
	for (int i=1; i<=n; i++){
		for (pair <int,int>&j: f)
            j.first=gcd(j.first,a[i]);

		f.push_back(make_pair(a[i], i));

		vector <pair <int,int> > cur;
		for (pair <int,int> j: f) {
			if (cur.empty()||cur.back().first!=j.first) cur.push_back(j);
		}

		f.swap(cur);
		for (pair <int,int> j: f) 
            ans[i-j.second+1] = max(ans[i-j.second+1], j.first);
	}

	for (int i=n-1; i>0; i--)
        ans[i] = max(ans[i],ans[i+1]);

	for (int i=1; i<=n; i++)
        cout<< ans[i] << " \n"[i==n];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while (t--) solve();
}