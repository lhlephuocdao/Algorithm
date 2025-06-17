#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>
const int mod = 998244353;

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        vector<int> parent(n+1);
        parent[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int p;
            cin >> p;
            parent[i] = p;
            adj[p].push_back(i);
            adj[i].push_back(p);
        }

        vector<vector<int>> d(n+1);
        d[0].push_back(1);

        function<void(int, int, int)> dfs = [&](int u, int prev, int dis){
            dis++;
            for (auto v : adj[u]) {
                if (v != prev) {
                    d[dis].push_back(v);
                    dfs(v, u, dis);
                }
            }
        };

        dfs(1, 0, 0);
        // for (int i = 0; i < n; i++) {
        //     for (auto v : d[i])
        //         cout << v << ' ';
        //     cout << '\n';
        // }

        function<int(int,int,int)> dfs2 = [&](int u, int prev, int dis){
            int ans = 1;
            dis++;

            if (u == 1) {
                for (auto v : adj[u]) {
                    ans += dfs2(v, u, dis);
                    ans %= mod;
                }
            } else {
                bool is_leaf = true;
                for (auto v : d[dis]) {
                    if (parent[v] != u) {
                        ans += dfs2(v, u, dis);
                        ans %= mod;
                        is_leaf = false;
                    }
                }
                if (is_leaf) return 1ll;
            }

            return ans;
        };

        cout << dfs2(1, 0, 0) << '\n';
    }

    return 0;
}