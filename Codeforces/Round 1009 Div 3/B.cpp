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
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        sort(a.begin(), a.end());
        if (n == 1) {
            cout << a[0] << '\n';
            continue;
        }

        int x = a[0] + a[1] - 1;
        for (int i = 2; i < n; i++) {
            x += a[i] - 1;
        }

        cout << x << '\n';
    }

    return 0;
}