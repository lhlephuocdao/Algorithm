#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 998244353;
#define sc second
#define fi first
#define all(x) x.begin(), x.end()

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

long long Pow(long long a, long long b) {
    long long ans = 1;
    while (b > 0){
        if (b % 2) ans = ans * a;
        a = a * a;
        b /= 2;
    }
    return ans;
}

int32_t main()
{
    fastio;

    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;

        int ans = 0;
        for (int i = 1; i <= 60; i++)
        {
            if (n < (1ll << i)) break;
            int y = n/(1ll << i);
            int x = sqrt(y);
            cout << "y : " << y << " x: " << x << '\n';
            ans += x;
        }

        cout << ans << '\n';
    }
    return 0;
}