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
        vector<int> a(n+1), prefix(n+1);
        prefix[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            prefix[i] = prefix[i-1] + a[i];
        }

        int ans = 0;
        map<int, int> m;
        int l = 0, r = 1;
        m[0]++;
        while (r <= n)
        {
            m[prefix[r]]++;
            if (m[prefix[r]] == 2) {
                ans++;
                m.clear();
                l = r;
                if (l <= n) m[prefix[l]]++;
                r = l+1;
            } else {
                r++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}