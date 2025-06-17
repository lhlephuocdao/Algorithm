#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;
 
// directions: 0=up, 1=right, 2=down, 3=left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
 
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
 
    int t = 1; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        int g = 0;
        for (auto& x : a) cin >> x, g = __gcd(g, x);
        for (auto& x : a) x /= g;

        const int MAX = 5000;
        vector<int> dp1(MAX+1, INT_MAX), dp2(MAX+1, INT_MAX);
        // dp1[x] : kích thước nhỏ nhất của tập con có gcd = x
        for (int i = 0; i < n; i++) {
            dp2 = dp1;
            dp2[a[i]] = 1;
            for (int j = 1; j <= MAX; j++) {
                if (dp1[j] < INT_MAX) {
                    int k = __gcd(j, a[i]);
                    dp2[k] = min(dp2[k], dp1[j] + 1);
                }
            }
            dp2.swap(dp1);
        }

        int cnt = 0;
        for (auto x : a)
            if (x == 1) cnt++;

        // cout << "g: " << g << " dp1[1] : " << dp1[1] << '\n';

        if (cnt == 0)
            cout << dp1[1] - 1 + n - 1 << '\n';
        else
            cout << n - cnt << '\n';
    }
    return 0;
}