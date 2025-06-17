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
        int n,l,r; cin >> n >> l >> r;
        vector<int> a(4*n), one(4*n);
        one[0] = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];

        // n chan -> increase n -> n le
        if (n%2 == 0) {
            n++;
            for (int i = 1; i <= n/2; i++)
                a[n] ^= a[i];
        }

        for (int i = 1; i <= n; i++)
            one[i] = (one[i-1] + a[i])%2;

        for (int i = n+1; i <= 2*n + 1; i++) {
            a[i] = one[i/2];
            one[i] = (one[i-1] + a[i])%2;
        }

        if (l <= 2*n + 1) {
            cout << a[l] << '\n';
        } else {
            int p = 0;
            for (int i = 1; i <= n; i++)
                p ^= a[i];

            int cnt = 1;
            l /= 2;
            while (l%2 == 0 && (l/2 > n)) {
                cnt++;
                l /= 2;
            }

            int ans = 0;
            if (cnt & 1) ans ^= p;
            if (l%2 == 0) ans ^= a[l];
            cout << ans << '\n';
        }
    }

    return 0;
}


    