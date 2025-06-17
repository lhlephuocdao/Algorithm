#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 998244353;
#define sc second
#define fi first

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

    int t; cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        int ans = 0;
        int i = n-1;
        for (; i>=0; i--) {
            if (s[i] == '0') {
                ans++;
            } else break;
        }
        // cout << "i: " << i << '\n';

        i--;
        for (; i >= 0; i--) {
            if (s[i] != '0')
                ans++;
        }

        // cout << "i: " << i << '\n';
        cout << ans << '\n';
    }
    return 0;
}