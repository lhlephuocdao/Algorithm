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
        int n,x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto& i : a) cin >> i;

        sort(a.begin(), a.end(), greater<int>());
        int ans = 0;
        int mi = INT_MAX;
        int count = 0;
        int s = 0;
        for (int i = 0; i < n; i++) {
            mi = min(mi, a[i]);
            count++;
            s = mi * count;
            // cout << "i: " << i << " " << mi << " " << count << " " << s << '\n';
            if (s >= x) {
                ans++;
                count = 0;
                mi = INT_MAX;
                s = 0;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}