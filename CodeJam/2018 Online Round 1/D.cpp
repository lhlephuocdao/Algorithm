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
    while (tc--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        vector<vector<pair<int, pii>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u,v,c,t;
            cin >> u >> v >> c >> t;
            u--, v--;
            adj[u].push_back({v, {c,t}});
            adj[v].push_back({u, {c,t}});
        }

        int lo = 1, hi = 1e5;
        int ans = 1;
        while (lo <= hi) {
            int p = (lo+hi)/2;
            // d[i] : chi phí để p người có thể đến được node i
            vector<int> d(n, INT_MAX);
            d[0] = 0;
            // pq : {distance, node}
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push({0, 0});

            while (!pq.empty()) {
                int d_u = pq.top().first;
                int u = pq.top().second;
                pq.pop();

                if (d[u] < d_u) continue;
                
                for (auto node : adj[u]) {
                    int v = node.first;
                    int c = node.second.first;
                    int t = node.second.second;

                    /* new_cost = cost tại u + chi phí đi từ u->v */
                    int d_v = d_u;
                    if (p>t) d_v += c*(p-t)*(p-t);
                    if (d_v < d[v]) {
                        d[v] = d_v;
                        pq.push({d_v, v});
                    }
                }
            }

            if (d[n-1] <= k) {
                ans = max(ans, p);
                lo = p + 1;
            } else {
                hi = p - 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}