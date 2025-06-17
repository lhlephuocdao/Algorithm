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
        int n,m,k,d;
        cin >> n >> m >> k >> d;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        vector<int> cost(n);
        for (int i = 0; i < n; i++)
        {
            vector<int> dp(m, 0);
            dp[0] = 1;
            multiset<int> s;
            s.insert(1);
            for (int l = 0, r = 1; r < m; r++)
            {
                if (r - l - 1 > d) {
                    s.erase(s.find(dp[l]));
                    l++;
                }

                dp[r] = *s.begin() + a[i][r] + 1;
                s.insert(dp[r]);
            }
            cost[i] = dp[m-1];
        }

        vector<int> pre(n, 0);
        pre[0] = cost[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i-1] + cost[i];

        int ans = pre[k-1];
        for (int i = k; i < n; i++)
            ans = min(ans, pre[i] - pre[i-k]);

        cout << ans << '\n';
    }

    return 0;
}