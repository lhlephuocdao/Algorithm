#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> c(n);
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            m[c[i]]++;
        }

        int count_one = 0;
        for (auto itr : m) {
            if (itr.second == 1) count_one++;
        }

        int ans = (count_one+1)/2;
        ans *= 2;
        ans += m.size()-count_one;
        cout << ans << '\n';
    }

    return 0;
}