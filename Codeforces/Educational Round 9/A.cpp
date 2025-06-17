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

    int t = 1;
    while (t--)
    {
        int n,p;
        cin >> n >> p;
        vector<string> a(n);
        for (auto& x : a) cin >> x;

        int ans = 0;
        int cur = 0;
        for (int i = n-1; i >= 0; i--)
        {
            ans += cur*p;
            cur *= 2;
            if (a[i] == "halfplus") {
                cur += 1;
                ans += 0.5*p;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}