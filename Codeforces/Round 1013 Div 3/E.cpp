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

    const int MAX_N = 1e7 + 5;
    vector<bool> is_prime(MAX_N, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;

        int count = 0;
        for (int g = 1; g <= n; g++) {
            for (int p : primes) {
                if (g * p > n) break;
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}