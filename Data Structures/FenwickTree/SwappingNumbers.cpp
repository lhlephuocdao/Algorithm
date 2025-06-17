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
            bit.assign(n+1, 0);
        }

        void update(int u, int v) {
            int idx = u;
            while (idx <= n) {
                bit[idx] += v;
                idx += (idx & (-idx));
            }
        }

        int query(int p) {
            int idx = p, ans = 0;
            while (idx > 0) {
                ans += bit[idx];
                idx -= (idx & (-idx));
            }
            return ans;
        }

        int rangeQuery(int l, int r) {
            return query(r) - query(l-1);
        }
};

int32_t main()
{
    fastio;

    int t = 1;
    while (t--)
    {
        int n; cin >> n;
        vector<int> p(n);
        for (auto& x : p) cin >> x;

        int ans = 0, cnt = 0;
        for (int i = 0; i < n-1; i++) {
            FenwickTree ft(n);
            for (int j = i+1; j < n; j++)
            {
                if (p[i] > p[j]) {
                    ans++;
                    int k = j-i-1;
                    int a = k - ft.query(p[j]);
                    int b = ft.query(p[i]-1);
                    cnt = max(cnt, 2*a + 2*b - 2*k + 1ll);
                }
                ft.update(p[j], 1);
            }
        }

        cout << ans - cnt << '\n';
    }
    return 0;
}