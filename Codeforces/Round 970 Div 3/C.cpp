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
        int l,r;
        cin >> l >> r;
        int x = 2*(r - l);

        int s = 1, e = 1e8;
        int ans = 0;
        while (s <= e)
        {
            int mid = (s+e)/2;

            if (mid*(mid-1) <= x) {
                ans = max(ans, mid);
                s = mid+1;
            } else {
                e = mid - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}