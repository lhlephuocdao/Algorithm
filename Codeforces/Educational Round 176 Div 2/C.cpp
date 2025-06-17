#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

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
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());
        vector<int> x(m);
        for (int i = 0; i < m; i++)
            x[i] = max(1ll, n-a[i]);

        // for (auto& b : x) cout << b << ' ';
        // cout << '\n';

        vector<int> pre(m, 0);
        pre[0] = x[0];
        for (int i = 1; i < m; i++)
            pre[i] = pre[i-1] + x[i];

        // for (auto& b : pre) cout << b << ' ';
        // cout << '\n';
        
        int ans = 0;
        for (int i = 0; i < m-1; i++) {
            auto f = lower_bound(a.begin()+i+1, a.end(), n-a[i]);
            if (f != a.end()) {
                int j = f - a.begin(); // 0-based index
                int y = min(a[i], n-1);
                int k = m - j;
                // cout << "i: " << i << " j: " << j << " y: " << y << " k: " << k << '\n';
                int sum = pre[m-1] - (j == 0 ? 0 : pre[j-1]);
                int tmp = k*(y+1) - sum;
                // cout << "sum: " << sum << " tmp: " << tmp << '\n';
                ans += 2*tmp;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}