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
        int n,m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                a[i][j] = s[j] - '0';
        }

        int r = 0, c = 0;
        for (int i = 0; i < n; i++) {
            int tot = 0;
            for (int j = 0; j < m; j++) {
                tot += a[i][j];
            }
            if (tot&1)
                r++;
        }

        for (int j = 0; j < m; j++) {
            int tot = 0;
            for (int i = 0; i < n; i++) {
                tot += a[i][j];
            }
            if (tot&1)
                c++;
        }

        cout << max(r, c) << '\n';
    }

    return 0;
}