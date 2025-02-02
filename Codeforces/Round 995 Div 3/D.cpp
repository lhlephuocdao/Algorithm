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
        int n,x,y;
        cin >> n >> x >> y;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n-1; i++)
        {
            int _min = sum - a[i] - y;
            int _max = sum - a[i] - x;

            int l, r;
            auto low = lower_bound(a.begin() + i + 1, a.end(), _min);
            l = low - a.begin();
            auto hi = upper_bound(a.begin() + i + 1, a.end(), _max);
            r = hi - 1 - a.begin();
            if (r >= l)
                ans += r-l+1;
        }
        cout << ans << '\n';
    }

    return 0;
}