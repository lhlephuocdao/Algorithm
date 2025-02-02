#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<vector<pair<int, int>>> adj(n+1);

    for (int i = 0; i < n-1; i++)
    {
        int x,y,t;
        cin >> x >> y >> t;
        adj[x].push_back({y, t});
        adj[y].push_back({x, t});
    }

    vector<bool> mark(n+1, false);
    vector<int> ans;
    function<void(int, int, int)> dfs = [&](int parent, int u, int prev) {
        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int t = neighbor.second;
            if (v != parent) {
                if (t == 2) { // problem road
                    mark[prev] = false;
                    mark[v] = true;
                    dfs(u, v, v);
                } else { // not problem road
                    dfs(u, v, prev);
                }
            }
        }
    };

    dfs(0, 1, 0);

    for (int i = 1; i <= n; i++)
        if (mark[i]) ans.push_back(i);

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';

    return 0;
}