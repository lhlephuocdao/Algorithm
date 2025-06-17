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
    cin >> t;
    while (t--)
    {
        int n,m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        vector<int> pre(m, -1), suf(m, -1);

        for (int i = 0, j = 0; i < n && j < m; i++) {
            if (a[i] >= b[j]) {
                pre[j] = i;
                j++;
            }
        }

        for (int i = n-1, j = m-1; i>=0 && j>=0; i--) {
            if (a[i] >= b[j]) {
                suf[j] = i;
                j--;
            }
        }

        // for (auto x : pre) cout << x << ' ';
        // cout << '\n';
        // for (auto x : suf) cout << x << ' ';
        // cout << '\n';

        if (pre[m-1] != -1 || suf[0] != -1) {
            cout << 0 << '\n';
            continue;
        }

        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            if (j==0 && suf[j+1] != -1) {
                ans = min(ans, b[j]);
            } else if (j==m-1 && pre[j-1] != -1) {
                ans = min(ans, b[j]);
            } else if (pre[j-1] != -1 && suf[j+1] != -1 && pre[j-1] < suf[j+1]) {
                ans = min(ans, b[j]);
            }
        }

        if (ans == INT_MAX) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}