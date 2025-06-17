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
        vector<int> b(2*n);
        map<int, int> mp;
        for (auto& x : b) cin >> x, mp[x]++;
        sort(b.begin(), b.end(), greater<int>());

        int x = 0;
        for (int i = 0; i < n; i++)
            x += b[i];

        for (int i = n; i < 2*n; i++)
            x -= b[i];

        if (mp[x] == 0) {
            vector<int> a(2*n+1);
            a[0] = x;

            for (int i = 0; i < n; i++)
                a[2*i+1] = b[i];

            int index = 2;
            for (int i = n; i < 2*n; i++) {
                a[index] = b[i];
                index += 2;
            }

            for (auto x : a)
                cout << x << ' ';
            cout << '\n';
        } else {
            int b1 = b[0];
            int b2 = b[1];

            int s = 0;
            for (int i = 2; i <= n; i++)
                s -= b[i];

            for (int i = n+1; i < 2*n; i++)
                s += b[i];

            // cout << "s: " << s << '\n';

            int v = b1 + b2 - s;
            cout << b1 << " " << v << " " << b2 << " ";
            
            for (int i = n+1; i < 2*n; i++)
                cout << b[i] << " " << b[i-n+1] << " ";
            cout << '\n';
        }
    }

    return 0;
}