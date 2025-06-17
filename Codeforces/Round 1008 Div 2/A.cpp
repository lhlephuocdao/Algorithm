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
        int n, x; cin >> n >> x;
        int total = 0;
        vector<int> a(n);
        for (auto& y : a) {
            cin >> y;
            total += y;
        }

        if (total%x == 0 && total/x == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}