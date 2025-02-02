#include <bits/stdc++.h>
using namespace std;
#define int long long

void log(vector<int>& a) {
    for (auto x : a) cout << x << ' ';
    cout << '\n';
}



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n,k; cin >> n >> k;
        int ans = 0;

        function<pair<int, int>(int, int)> back = [&](int l, int r) -> pair<int, int> {
            pair<int, int> ret;
            int len = r-l+1;
            if (len < k) return {0, 0};
            int m  = (l+r)/2;
            if (len%2 == 0) {
                auto sol = back(l,m);
                ret = {sol.first*2 + sol.second*m, sol.second * 2};
            } else {
                auto sol = back(l,m);
                ret = m + back(l,m-1) + back(m+1,r);
            }
        };

        
        cout << ans << '\n';
    }

    return 0;
}