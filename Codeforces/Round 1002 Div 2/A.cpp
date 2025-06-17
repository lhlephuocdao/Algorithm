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
        int n; 
        cin >> n;
        vector<int> a(n), b(n);
        map<int, int> ma, mb;
        for (auto& x : a) {
            cin >> x;
            ma[x]++;
        }

        for (auto& x : b) {
            cin >> x;
            mb[x]++;
        }

        if (ma.size() >= 3 || mb.size() >= 3 || (ma.size() == 2 && mb.size() == 2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}