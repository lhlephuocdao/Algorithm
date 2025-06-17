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
        int n,k;
        cin >> n >> k;
        string s; cin >> s;
        bool pos = true;
        for (int i = 0; i < n-k; i++) {
            if (s[i] == '?' || s[i+k] == '?') {
                if (s[i] != '?') s[i+k] = s[i];
                if (s[i+k] != '?') s[i] = s[i+k];
                // còn case s[i] và s[i+k] đều bằng ? chưa xử lý
            } else {
                if (s[i] != s[i+k]) {
                    pos = false;
                    break;
                }
            }
        }

        for (int i = n-1; i >= k; i--) {
            if (s[i] == '?' || s[i-k] == '?') {
                if (s[i] != '?') s[i-k] = s[i];
                if (s[i-k] != '?') s[i] = s[i-k];
            } else if (s[i] != s[i-k]) {
                pos = false;
                break;
            }
        }

        // cout << "s: \n";
        // cout << s << '\n';

        int one = 0, unknow = 0;
        for (int i = 0; i < k; i++)
            if (s[i] == '1') one++;
            else if (s[i] == '?') unknow++;

        if (one > k/2) pos = false;
        else {
            int need_one = k/2 - one;
            for (int i = 0; i < k; i++)
                if (s[i] == '?') {
                    if (need_one > 0) {
                        s[i] = '1';
                        need_one--;
                    } else s[i] = '0';
                }

            if (need_one > 0) pos = false;

            for (int i = k; i < n; i++) {
                if (s[i] == '?') s[i] = s[i-k];
                else if (s[i] != s[i-k]) {
                    pos = false;
                    break;
                }
            }
        }

        if (!pos) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}