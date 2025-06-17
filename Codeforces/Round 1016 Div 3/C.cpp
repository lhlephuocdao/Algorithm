#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 998244353;
#define sc second
#define fi first

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

 bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int32_t main()
{
    fastio;

    int t; cin >> t;
    while (t--)
    {
        int x, k;
        cin >> x >> k;

        if (isPrime(x) && k == 1) {
            cout << "YES\n";
        } else
            cout << "NO\n";
    }
    return 0;
}