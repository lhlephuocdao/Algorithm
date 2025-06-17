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
// 4=up-left, 5=down-right, 6=up-right, 7=down-left
int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

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
        int n,k,m;
        cin >> n >> k >> m;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        while (m--) {
            int i; cin >> i;
            if (i > 0) {
                if (k <= i)
                    k = i - k + 1;
            } else {
                if (k >= n + i + 1)
                    k = 2*n+i+1-k;
            }
        }
        cout << k << '\n';
    }

    return 0;
}