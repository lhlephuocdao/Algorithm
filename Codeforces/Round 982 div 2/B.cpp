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
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = LONG_LONG_MAX;
        for (int i = 1; i <= n; i++)
        {
            int ret = i-1;
            for (int j = i+1; j <= n; j++)
                if (a[j] > a[i]) ret++;
            ans = min(ans, ret);
        }
        cout << ans << '\n';
    }

    return 0;
}