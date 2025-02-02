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
        int l,r,k;
        cin >> l >> r >> k;
        int m = r/k;
        int ans = 0;
        if (m >= l) ans = m - l + 1;
        cout << ans << '\n';
    }

    return 0;
}