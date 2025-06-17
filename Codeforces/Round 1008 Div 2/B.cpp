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
        int n, k; cin >> n >> k;

        // if (k%2 == 1) {
        //     for (int i = 1; i < n; i++)
        //         cout << n << ' ';
        //     cout << n-1 << '\n';
        // } else {
        //     for (int i = 1; i < n-1; i++)
        //         cout << n-1 << ' ';
        //     cout << n << ' ' << n-1 << '\n';
        // }

        int index = n-k+1;
        int value = n-k+2;

        if (k >= n) {
            for (int i = 1; i <= n; i++)
                cout << (i+1)%n << ' ';
            cout << '\n';
            continue;
        }

        if (k == 1) {
            for (int i = 1; i < n; i++)
                cout << n << ' ';
            cout << n-1 << '\n';
            continue;
        }

        vector<int> a(n+1);
        int i = index;
        int v = value;
        a[n] = value-1;
        while (i <= n && v <= n) {
            a[i] = v;
            v++;
            i++;
        }

        for (int j = index-1; j >= 1; j--)
            a[j] = value-1;

        for (int j = 1; j <= n; j++)
            cout << a[j] << ' ';
        cout << '\n';
    }

    return 0;
}