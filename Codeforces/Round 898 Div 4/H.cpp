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
        int n,a,b;
        cin >> n >> a >> b;
        a--, b--;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (a == b) {
            cout << "NO\n";
            continue;
        }

        vector<bool> isCycle(n, false);
        vector<bool> mark(n, false);
        vector<int> s;
        bool found = false;

        function<void(int, int)> dfs = [&](int u, int prev) {
            mark[u] = true;
            s.push_back(u);
            for (auto v : adj[u]) {
                if (found) return;
                if (v != prev) {
                    if (mark[v]) {
                        for (int i = s.size()-1; i >= 0; i--) {
                            isCycle[s[i]] = true;
                            if (s[i] == v) break;
                        }
                        found = true;
                        return;
                    } else {
                        dfs(v, u);
                    }
                }
            }
            s.pop_back();
        };
        dfs(0, -1);

        if (isCycle[b]) {
            cout << "YES\n";
            continue;
        }

        function<vector<int>(int)> bfs = [&](int src) {
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;
            queue<int> q;
            q.push(src);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto v : adj[u]) {
                    if (dist[u] + 1 < dist[v]) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            return dist;
        };

        vector<int> db = bfs(b); // min distance from b
        int y;
        int d1 = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i != b && isCycle[i]) {
                if (db[i] < d1) {
                    d1 = db[i];
                    y = i;
                }
            }
        }

        vector<int> da = bfs(a); // min distance from a
        int d2 = da[y];
        if (d1 >= d2)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}