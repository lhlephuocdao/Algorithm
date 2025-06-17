#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

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
        int n,m,p,k;
        cin >> n >> m >> p >> k;
        vector<int> c(n);
        for (auto& x : c) cin >> x;
        vector<vector<int>> out(n);
        vector<int> degree(n, 0);
        for (int i = 0; i < m; i++) {
            int x,y;
            cin >> x >> y;
            x--; y--;
            out[x].push_back(y);
            degree[y]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[i] == 0) q.push(i);

        vector<int> order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            order.push_back(u);

            for (auto v : out[u]) {
                if (degree[v] > 0) degree[v]--;
                if (degree[v] == 0) q.push(v);
            }
        }

        int ans = 0;
        for (auto u : order) {
            // node u is removed at c[u]
            if (c[u] <= k) {
                ans += c[u] - 1;
                ans %= mod;
            } else {
                ans += k;
                ans %= mod;
            }

            for (auto v : out[u]) {
                // update c[v] > c[u]
                // c[v] = c[v] + x*p > c[u]
                // x*p > (c[u] - c[v])
                // x > (c[u] - c[v])/p
                if (c[v] < c[u]) {
                    int x = (c[u] - c[v])/p + 1;
                    c[v] = c[v] + x*p;
                }
            }
        }

        // trường hợp có cycle a -> b -> c -> a
        // a,b,c đều đóng góp k lần
        for (int i = 0; i < n; i++)
            if (degree[i] != 0) {
                ans += k;
                ans %= mod;
            }

        cout << ans << '\n';
    }

    return 0;
}