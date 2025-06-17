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
        vector<int> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        int ans = 0;
        
        // c1 : a chẵn và b lẻ
        // c2 : a lẻ và b chẵn
        vector<int> c1(n+1, 0), c2(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            if (a[i] == b[i]) {
                ans = i+1;
                break;
            }
            bool check = false;
            // Not remove
            if (i%2 == 0) {
                check = c2[a[i]] | c1[b[i]];
            } else {
                check = c1[a[i]] | c2[b[i]];
            }

            // Remove i+1
            if (check == false && i+1 < n) {
                if ((i+1)%2 == 0) {
                    // i lẻ
                    c1[a[i+1]]--;
                    c2[b[i+1]]--;

                    check = c1[b[i]] | c2[a[i]];

                    c1[a[i+1]]++;
                    c2[b[i+1]]++;
                } else {
                    // i chẵn
                    c2[a[i+1]]--;
                    c1[b[i+1]]--;

                    check = c1[a[i]] | c2[b[i]];

                    c2[a[i+1]]++;
                    c1[b[i+1]]++;
                }
            }

            if (check) {
                ans = i+1;
                break;
            }

            if (i%2 == 0) {
                c1[a[i]]++;
                c2[b[i]]++;
            } else {
                c2[a[i]]++;
                c1[b[i]]++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}