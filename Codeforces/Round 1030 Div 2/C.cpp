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

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n,k; cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        // Cần đếm tại mỗi bit có bao nhiêu số vẫn đang là zero : 0
        // Ví dụ: Trong n số, tại bit thứ i-th có x số đang là zero
        // -> Cần x * (1<<i) operations

        int ans = 0;
        for (int i = 0; i < 60; i++) {
            // Xét tại bit i-th
            for (int j = 0; j < n; j++) {
                if (a[j] & (1ll<<i)) ans++;
                else {
                    if (k >= (1ll<<i)) {
                        k -= (1ll<<i);
                        ans++;
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}