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
        int n, m;
        cin >> n >> m;
        int ans = 0;
        bool pos = true;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (pos && s.length() <= m) {
                ans++;
                m -= s.length();
            } else
                pos = false;
        }
        cout << ans << '\n';
    }

    return 0;
}