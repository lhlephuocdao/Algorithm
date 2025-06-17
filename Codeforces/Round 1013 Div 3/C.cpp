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
        int n;
        cin >> n;
        if (n%2 == 0) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> a(n+1);
        a[1] = 1;
        int move = 1;
        for (int i = n; i > 1; i--) {
            int idx = i-move;
            if (idx <= 0) idx += n;
            a[idx] = i;
            move++;
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}