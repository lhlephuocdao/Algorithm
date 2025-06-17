#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 998244353;
#define sc second
#define fi first

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

 void debug(vector<pair<int, int>>& a)
 {
     for (auto x : a)
     {
        cout << x.first << " " << x.second << '\n';
     }
 }

int32_t main()
{
    fastio;

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
        }

        vector<pair<bool, pair<int, int>>> node(n);
        // {visited, {root, distance}}
        for (int i = 0; i < n; i++)
            node[i] = {false, {i, 0}};

        int ans = 0;
        set<int> s;
        function<void(int, int, int)> dfs = [&](int u, int root, int d){
            for (auto v : adj[u])
            {
                if (node[v].first == false) { // unvisited
                    node[v] = {true, {root, d+1}};
                    dfs(v, root, d+1);
                } else {
                    if (node[v].sc.fi == v) { // v is root
                        s.erase(v);
                        node[v] = {true, {root, d+1}};
                        s.insert(root);
                        // 'root' is root of v
                    } else { // v is not root
                        int root_v = node[v].second.first;
                        while (root_v != node[root_v].second.first)
                            root_v = node[root_v].second.first;

                        int x = node[v].second.second;
                        int y = d+1;
                        if (x > y) { // inverse y roads
                            ans += y;
                            s.erase(root);
                            node[root].second = {node[v].second.first, x+1};
                        }
                    }
                }
            }
        };
    }
    return 0;
}