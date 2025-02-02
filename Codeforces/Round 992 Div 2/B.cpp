#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    int ans = 2;
    while (n > 2 && ((n-2 + 1)/2 >= 2)) {
        ans++;
        n = (n-2 + 1)/2;
        // cout << "n: " << n << '\n';
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}