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
        int n,d;
        cin >> n >> d;
        vector<int> ans;
        ans.push_back(1);
        if (d == 5) ans.push_back(5);

        /* 3 */
        if (d%3 == 0 || n >= 3)
            ans.push_back(3);

        /* 9 */
        if (d==9 || n >= 6 || (d%3==0 && n>=3))
            ans.push_back(9);

        /* 7 */
        if (d == 7 || n>=3)
            ans.push_back(7);

        sort(ans.begin(), ans.end());
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}