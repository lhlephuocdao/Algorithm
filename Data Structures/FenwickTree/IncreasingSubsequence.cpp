/*
    https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/increasing-subsequence-1-2d4df2d3/
*/
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

class FenwickTree {
    private:
        int n;
        vector<int> bit;
    
    public:
        FenwickTree(int n_) : n(n_) {
            bit.assign(n+1, INT_MAX);
        }
    
        void update(int u, int v) {
            int idx = u;
            while (idx <= n) {
                bit[idx] = min(bit[idx],v);
                idx += (idx & (-idx));
            }
        }
    
        int query(int p) {
            int idx = p, ans = INT_MAX;
            while (idx > 0) {
                ans = min(ans, bit[idx]);
                idx -= (idx & (-idx));
            }
            return ans;
        }
    };

int32_t main()
{
    fastio;

    int t = 1;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        
        vector<vector<int>> dp(k+1, vector<int>(n+1, INT_MAX));
        // dp[l][i] : min starting value of increasing subsequence of length l ending at i
        for (int i = 1; i <= n; i++)
            dp[1][i] = a[i];

        vector<int> v = a;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        function<int(int)> getIndex = [&](int x){
            int idx = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
            return idx;
        };

        // O(n*k*log(n))
        for (int l = 2; l <= k; l++)
        {
            FenwickTree ft(n);
            // update dp[l-1][1] vào vị trí của a[1]
            ft.update(getIndex(a[1]), dp[l-1][1]);
            for (int i = 2; i <= n; i++)
            {
                // dp[l][i] = min of all dp[l-1][j] (j<i) if a[j] < a[i]
                // ft.query(x) : get min dp[l-1] trong đoạn [1, x]
                int id = getIndex(a[i]);
                dp[l][i] = min(dp[l][i], ft.query(id-1));
                ft.update(id, dp[l-1][i]);
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (dp[k][i] != INT_MAX)
                ans = max(ans, a[i] - dp[k][i]);

        if (ans == 0) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}