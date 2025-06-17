#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;
const int INF = 1e18;

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

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        // a1, a2, a3, ... , an
        // decrease a[i] by i
        // decrease a[i] by n-i+1
        int y = (a[n] - n*a[1]);
        if (y % (1ll - n*n) != 0) {
            cout << "NO\n";
            continue;
        } else {
            y /= (1ll - n*n);
        }

        int x = a[1] - y*n;
        if (x<0 || y<0) {
            cout << "NO\n";
            continue;
        }

        bool check = true;
        for (int i = 2; i < n; i++) {
            if (a[i] != (x*i + y*(n-i+1))) {
                check = false;
                break;
            }
        }

        cout << (check ? "YES\n" : "NO\n");
    }

    return 0;
}