#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<vector<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<set<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<int>& a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

int32_t main()
{
    fastio;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        const int maxn = 1e5;
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n-1; i++)
        {
            int u,v,c;
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        int ans = 0;
        function<void(int, int, int)> dfs = [&](int u, int prev, int sum){
            bool is_leaf = true;
            for (auto x : adj[u]) {
                int v = x.first;
                int c = x.second;
                if (v != prev) {
                    is_leaf = false;
                    dfs(v, u, sum+c);
                }
            }
            if (is_leaf)
                ans = max(ans, sum);
        };

        dfs(0, -1, 0);

        cout << ans << '\n';
    }
    return 0;
}