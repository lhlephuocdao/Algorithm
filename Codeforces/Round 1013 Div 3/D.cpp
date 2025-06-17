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
        int n,m,k;
        cin >> n >> m >> k;
        int len = k/n;
        if (k%n != 0) len++;

        if (len == m) {
            cout << m << '\n';
            continue;
        }

        int x = (m+1)/2;
        if (len <= x) {
            cout << 1 << '\n';
        } else {
            int cnt = m+1 - len;
            int ans = len/cnt;
            if (len%cnt != 0) ans++;
            cout << ans << '\n';
        }
    }

    return 0;
}