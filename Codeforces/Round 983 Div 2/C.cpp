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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int ans = n-2;
        int l = 0;
        for (int r = 2; r < n; r++)
        {
            while (l <= r-2 && (a[l] + a[l+1] <= a[r])) l++;
            ans = min(ans, n - (r-l+1));
        }
        
        cout << ans << '\n';
    }

    return 0;
}