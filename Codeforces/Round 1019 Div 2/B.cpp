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
        int n; cin >> n;
        string s;
        cin >> s;
        int cost = n;
        s = '0' + s;
        n++;
        for (int i = 0; i < n-1; i++)
            if (s[i] != s[i+1])
                cost++;

        int l = 0, r = n-1;
        bool check = false;
        while (l+1 < r-1) {
            if (s[l] =='0' && s[l+1] == '1' && s[r-1] == '0' && s[r] == '1')
            {
                check = true;
                break;
            } else {
                if (s[l] == '0' && s[l+1] == '1') r--;
                else if (s[r-1] == '0' && s[r] == '1') l++;
                else {
                    l++; r--;
                }
            }
        }
        if (check) cost -= 2;

        int i = 0;
        while (i<n && s[i] == '0') i++;

        // s[i] = '1'
        while (i<n && s[i] == '1') i++;

        if (i<n && !check) cost -= 1;

        reverse(s.begin()+1, s.end());
        int c2 = n-1;
        for (int i = 0; i < n-1; i++)
            if (s[i] != s[i+1])
                c2++;
        
        cost = min(cost, c2);

        cout << cost << '\n';
    }
    return 0;
}