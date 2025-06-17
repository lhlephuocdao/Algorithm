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
        string a, b;
        cin >> a >> b;
        int i = 0, j = 0;
        int n = a.length(), m = b.length();
        while (i<n && a[i] == '0') i++;
        while (j<m && b[j] == '0') j++;

        int remain_a = n-i;
        int remain_b = m-j;

        if (remain_a < remain_b) {
            cout << "<" << '\n';
            break;
        } else if (remain_a > remain_b) {
            cout << ">" << '\n';
            break;
        }

        bool equal = true;
        while (i<n && j<m)
        {
            int x = a[i] - '0';
            int y = b[j] - '0';
            if (x < y) {
                cout << "<" << '\n';
                equal = false;
                break;
            } else if (x > y) {
                cout << ">" << '\n';
                equal = false;
                break;
            }
            i++,j++;
        }

        if (equal)
            cout << "=" << '\n';
    }
    return 0;
}