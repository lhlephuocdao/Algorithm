#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define pii pair<int, int>
#define int long long

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int a,b;
        cin >> a >> b;
        a--; b--;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++)
        {
            int u,v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        /*
            1 tree has n-1 edges, so to visit all nodes from root then come back to root
            we need total 2*(n-1) moves
        */

        vector<int> da(n), db(n);
        // distance from a (or b) to all other nodes
        da[a] = 0;
        db[b] = 0;

        function<void(int, int, vector<int>&)> dfs = [&](int u, int prev, vector<int>& d){
            for (auto v : adj[u]) {
                if (v == prev) continue;
                d[v] = d[u] + 1;
                dfs(v, u, d);
            }
        };

        dfs(a, -1, da);
        dfs(b, -1, db);

        // for (auto x : da) cout << x << ' ';
        // cout << '\n';

        // for (auto x : db) cout << x << ' ';
        // cout << '\n';

        int root = -1;
        int min_dis = n;
        for (int i = 0; i < n; i++) {
            if (da[i] == db[i] && da[i] < min_dis) {
                min_dis = da[i];
                root = i;
            }
        }

        if (root != -1) {
            int total = 0;
            function<void(int, int)> dfs2 = [&](int u, int prev){
                for (auto v : adj[u]) {
                    if (v == prev) continue;
                    total++;
                    dfs2(v, u);
                    total++;
                }
            };
            dfs2(root, -1);

            // cout << "total: " << total << '\n';

            int max_deep = 0;
            vector<int> dis(n);
            dis[root] = 0;
            dfs(root, -1, dis);
            // for (auto x : dis) cout << x << ' ';
            // cout << '\n';

            for (int i = 0; i < n; i++)
                max_deep = max(max_deep, dis[i]);

            // cout << "max_deep: " << max_deep << '\n';

            int ans = total - max_deep + min_dis;
            cout << ans << '\n';
        } else {
            int total = 0;
            function<void(int, int)> dfs2 = [&](int u, int prev){
                for (auto v : adj[u]) {
                    if (v == prev) continue;
                    total++;
                    dfs2(v, u);
                    total++;
                }
            };
            dfs2(a, -1);

            // cout << "total: " << total << '\n';

            int max_deep = 0;
            for (int i = 0; i < n; i++)
                max_deep = max(max_deep, da[i]);

            int ans = total - max_deep + da[b];
            cout << ans << '\n';
        }
    }
    return 0;
}