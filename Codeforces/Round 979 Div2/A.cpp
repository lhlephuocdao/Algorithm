#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int maxa = INT_MIN, mina = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxa = max(maxa, a[i]);
            mina = min(mina, a[i]);
        }
        int ans = (maxa - mina)*(n-1);
        cout << ans << '\n';
    }

    return 0;
}