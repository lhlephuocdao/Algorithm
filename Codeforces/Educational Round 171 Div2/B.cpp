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
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (n%2 == 0) {
            int ans = 0;
            for (int i = 0; i < n; i+=2)
                ans = max(ans, a[i+1] - a[i]);
            cout << ans << '\n';
        } else {
            vector<int> sf(n);
            vector<int> pf(n);
            for (int i = 0; i < n - 1; i+=2) {
                pf[i + 1] = a[i + 1] - a[i];
            }
            for (int i = 1; i < n - 1; i+= 2) {
                sf[i] = a[i + 1] - a[i];
            }
        
            for (int i = 1; i < n; i++) {
                pf[i] = max(pf[i], pf[i - 1]);
            }
            for (int i = n - 2; i >= 0; i--) {
                sf[i] = max(sf[i], sf[i + 1]);
            }

            // for (int i = 0; i < n; i++) cout << pf[i] << ' ';
            // cout << '\n';
            // for (int i = 0; i < n; i++) cout << sf[i] << ' ';
            // cout << '\n';
        
            long long bestRes = LLONG_MAX;
            for (int i = 0; i < n; i+= 2) {
                bestRes = min(bestRes, max(1ll, max(pf[i], sf[i])));
            }
            cout << bestRes << '\n';
        }
    }

    return 0;
}