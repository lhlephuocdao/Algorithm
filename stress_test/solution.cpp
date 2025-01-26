#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

int32_t main()
{
    fastio;
    
    int t = 1; 
    // cin >> t;
    while (t--) 
    {
        int n; 
        cin >> n;
        vector<int> a(n);
        int ans = 0;
        for (auto& x : a) {
            cin >> x;
            ans = max(ans, x);
        }

        if (ans == 100)
            cout << -1 << '\n';
        else
            cout << ans << '\n';

    }
    return 0;
}