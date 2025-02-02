#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 998244353;

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug
 * stress test
 */

struct DSU {
    vector<int> parent, sz;

    DSU(int n) : parent(n), sz(n) {};

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }

    void join_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

int32_t main()
{
    fastio;

    int t; cin >> t;
    while (t--)
    {
        int n,m1,m2;
        cin >> n >> m1 >> m2;
        vector<vector<int>> F(n);
        DSU DG(n);
        for (int i = 0; i < n; i++) {
            DG.make_set(i);
        }

        for (int i = 0; i < m1; i++) {
            int u,v; cin >> u >> v;
            u--; v--;
            F[u].push_back(v);
            F[v].push_back(u);
        }

        for (int i = 0; i < m2; i++) {
            int u,v; cin >> u >> v;
            u--; v--;
            DG.join_sets(u,v);
        }

        int ans = 0;
        vector<bool>  visited(n, false);
        function<int(int, int)> dfs = [&](int u, int prev) -> int {
            visited[u] = true;
            int root_u = DG.find_set(u);
            for (auto x : F[u]) {
                if (x == prev || visited[x]) continue;
                int root_x = DG.find_set(x);
                if (root_u != root_x) {
                    ans++;
                    continue;
                } else {
                    dfs(x, u);
                }
            }
            return root_u;
        };

        map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false) {
                cnt[dfs(i, -1)]++;
            }
        }

        for (auto it : cnt) {
            ans += it.second - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}