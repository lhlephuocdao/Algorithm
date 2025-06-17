#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;

// directions: 0=up, 1=right, 2=down, 3=left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

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
    while (t--)
    {
        const int mod = 1e9;
        int n,k;
        cin >> n >> k;
        if (k>n)
            cout << 1 << '\n';
        else {
            vector<int> a(n+1);
            for (int i = 0; i < k; i++)
                a[i] = 1;
            
            int sum = k;
            for (int i = k, j = 0; i <= n; i++, j++)
            {
                a[i] = sum;
                sum = (sum + a[i] - a[j] + mod)%mod;
            }
            cout << a[n] << '\n';
        }
    }
    return 0;
}