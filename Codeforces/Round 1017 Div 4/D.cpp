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
    cin >> t;
    while (t--)
    {
        string p,s;
        cin >> p >> s;
        int n = p.length(), m = s.length();

        if (m > 2*n) {
            cout << "NO\n";
            continue;
        }

        int i = 0, j = 0;
        bool check = true;
        while (i<n) {
            char c = p[i];
            int x = 0;
            while (i<n && p[i] == c) x++, i++;
            // đối với s, s cần có ít nhất x kí tự c, nhiều nhất 2x
            int y = 0;
            while (j<m && s[j] == c) y++, j++;
            if (y<x || y>2*x) {
                check = false;
                break;
            }
        }

        cout << ((check && j == m) ? "YES" : "NO") << '\n';
    }
    return 0;
}