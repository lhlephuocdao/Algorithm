#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug :
 *      - duplicated element
 *      - consecutive range: 1 2 3 4 5 ....
 * stress test
 */

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int x,n,m;
        cin >> x >> n >> m;
        
        if (n >= 32) {
            cout << 0 << " " << 0 << '\n';
            continue;
        }

        if (n+m == 0) {
            cout << x << " " << x << '\n';
            continue;
        }

        int ans1, ans2;
        int a = n, b = m, y = x;
        // find min
        while (a + b > 0) {
            if (b > 0) {
                b--;
                y = (y+1)/2;
                if (y <= 1) b = 0;
            } else {
                a--;
                y /= 2;
                if (y == 0) break;
            }
        }
        ans1 = y;

        a = n, b = m, y = x;
        //find max
        while (a+b > 0) {
            if (a>0) {
                a--;
                y /= 2;
                if (y == 0) break;
            } else {
                b--;
                y = (y+1)/2;
                if (y <= 1) break;
            }
        }
        ans2 = y;

        cout << ans1 << " " << ans2 << '\n';
    }

    return 0;
}