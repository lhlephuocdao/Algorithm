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
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        bool in = true, de = true;
        int len = 1, ans = 0;
        int i = 0;
        for (int i = 0; i < n-1; i++)
        {
            int x = a[i], y = a[i+1];
            // cout <<" i : " << i << " x : " << x << " y : " << y << '\n';
            if (in && x < y) {
                len++;
                in = false;
                de = true;
            } else if (de && x > y) {
                len++;
                de = false;
                in = true;
            } else {
                ans += len*(len-1)/2;
                len = 1;
                in = true;
                de = true;
                if (x != y) i--;
            }
        }

        if (len>1) ans += len*(len-1)/2;
        cout << ans << '\n';
    }

    return 0;
}


    