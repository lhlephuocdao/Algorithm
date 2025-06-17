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
        int n, k;
        cin >> n >> k;
        vector<int> b(n);
        for (auto& x : b) cin >> x;
        sort(b.begin(), b.end());

        int m = n - k;
        vector<pair<int,int>> iter;
        iter.reserve(k+1);

        for (int l = 0; l + m - 1 < n; l++){
            int r = l + m - 1;
            if (m % 2 == 1) {
                int med = b[l + (m-1)/2];
                iter.emplace_back(med, med);
            } else {
                int lo = b[l + m/2 - 1];
                int hi = b[l + m/2];
                iter.emplace_back(lo, hi);
            }
        }

        sort(iter.begin(), iter.end());
        int ans = 0;
        int curL = iter[0].first, curR = iter[0].second;
        for (int i = 1; i < (int)iter.size(); i++){
            int L = iter[i].first, R = iter[i].second;
            if (L > curR) {
                ans += (curR - curL + 1);
                curL = L;
                curR = R;
            } else {
                curR = max(curR, R);
            }
        }
        ans += (curR - curL + 1);

        cout << ans << "\n";
    }
    return 0;
}