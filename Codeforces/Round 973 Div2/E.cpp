#include <bits/stdc++.h>

using namespace std;

int a[200200];
int n;

void solve(){
    cin >> n;
    int g = 0, cur = 0;
    long long ans = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    for(int i=0;i<n;i++){
        a[i] /= g;
    }
    cout << "g: " << g << '\n';
    for(int t=0;t<n;t++){
        int nc = 1e9;
        cout << "nc: ";
        for(int i=0;i<n;i++){
            nc = min(nc, __gcd(cur, a[i]));
            cout << nc << " ";
        }
        cur = nc;
        cout << "\nt: " << t << " cur: " << cur << '\n';
        ans += cur;
        if(cur == 1) {
            ans += n - t - 1;
            break;
        }
    }
    cout << ans * g << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
     cin >> t;
    while(t--){
        solve();
    }
}