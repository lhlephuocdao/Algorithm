#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

int32_t main()
{
    fastio;
    
    int t = 1; 
    cin >> t;
    while (t--) 
    {
        int n, k; 
        cin >> n >> k;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        if (n == k) {
            vector<int> tmp;
            tmp.push_back(0);

            for (int i = 2; i <= n; i += 2) tmp.push_back(a[i]);
            tmp.push_back(0);
            // for (auto x : tmp) cout << x << ' ';
            // cout << '\n';
            for (int i = 1; i < tmp.size(); i++)
            {
                if (tmp[i] != i) {
                    cout << i << '\n';
                    break;
                }
            }
        } else {
            bool check = false;
            for (int i = 2; i <= (n-k+2); i++) {
                if (a[i] != 1) {
                    check = true;
                    cout << 1 << '\n';
                    break;
                }
            }
            if (!check)
                cout << 2 << '\n';
        }
    }
    return 0;
}