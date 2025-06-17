#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

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
        vector<int> vv(n+1);
        for (int i = 1; i <= n; i++) cin >> vv[i];
        vector<vector<int>> adj(n+1);
        int root;
        for (int i = 1; i <= n; i++)
        {
            int p; cin >> p;
            if (p == 0) root = i;
            else {
                adj[p].push_back(i);
                adj[i].push_back(p);
            }
        }

        vector<vector<int>> d(n+1, vector<int>(2, 0));
        // d[i][0] : no take node i
        // d[i][1] : take node i

        function<void(int,int)> dfs = [&](int u, int prev) {
            bool is_leaf = true;
            bool has = false;
            int diff = LONG_LONG_MIN;
            for (auto v : adj[u]) {
                if (v != prev) {
                    dfs(v, u);

                    is_leaf = false;
                    // not take node u -> need to take at least one child node of u
                    // -> if u has more than one child node -> get maximum (d[v][1], d[v][0]) for all child nodes
                    // -> if u has only one node -> take this node
                    if (adj[u].size() > 2 || (u == root && adj[u].size() > 1)) {
                        d[u][0] += max(d[v][1], d[v][0]);

                        if (d[v][1] >= d[v][0]) {
                            has = true;
                        } else {
                            diff = max(diff, d[v][1] - d[v][0]);
                        }
                    } else {
                        has = true;
                        d[u][0] = d[v][1];
                    }

                    //if take u -> not take child nodes of u
                    d[u][1] += d[v][0];
                }
            }

            // nếu tất cả d[v][0] > d[v][1] -> cần bỏ ra 1 d[v][0] và thêm vào 1 d[v][1]
            // -> d[u][0] += d[v][1] - d[v][0]
            // -> chọn v sao cho d[v][1] - d[v][0] (< 0) lớn nhất
            // cout << "has : " << has << " diff: " << diff << '\n';
            if (has == false) {
                d[u][0] += diff;
            }

            if (is_leaf) {
                d[u][0] = 0;
                d[u][1] = vv[u];
            } else {
                d[u][1] += vv[u];
            }

            // cout << "d[" << u << "]: " << d[u][0] << " " << d[u][1] << '\n';
        };

        dfs(root, 0);

        cout << max(d[root][0], d[root][1]) << '\n';
    }

    return 0;
}


    