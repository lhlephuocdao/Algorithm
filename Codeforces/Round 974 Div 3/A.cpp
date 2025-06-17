#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,k; cin >> n >> k;
        vector<int> a(n);
        int s = 0, ans = 0;
        for (auto& x : a) {
            cin >> x;
            if (x >= k)
                s += x;

            if (x == 0 && s > 0) {
                ans++;
                s--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}