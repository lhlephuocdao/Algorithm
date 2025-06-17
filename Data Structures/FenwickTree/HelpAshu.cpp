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
        int n;
        cin >> n;
        vector<int> a(n+1);
        FenwickTree ft1(n+1), ft2(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] & 1)
                ft1.update(i, 1);
            else
                ft2.update(i, 1);
        }
        
        int q; cin >> q;
        while (q--) {
            int type,x,y;
            cin >> type >> x >> y;
            if (type == 0) {
                if (a[x] & 1) {
                    if (y%2 == 0) {
                        // a[x] from odd to even
                        ft1.update(x, -1);
                        ft2.update(x, 1);
                    }
                } else {
                    if (y & 1) {
                        // a[x] from even to odd
                        ft1.update(x, 1);
                        ft2.update(x, -1);
                    }
                }
                a[x] = y;
            } else if (type == 1) {
                cout << ft2.rangeQuery(x, y) << '\n';
            } else {
                cout << ft1.rangeQuery(x, y) << '\n';
            }
        }
    }
    return 0;
}