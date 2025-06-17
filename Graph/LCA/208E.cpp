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
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
 
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
    while (t--)
    {
        int n; cin >> n;
        vector<int> par(n), roots;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            cin >> par[i];
            par[i]--;
            if (par[i] == -1)
                roots.push_back(i);
            else {
                adj[i].push_back(par[i]);
                adj[par[i]].push_back(i);
            }
        }

        int lg = __lg(n);
        vector<vector<int>> up(n, vector<int>(lg+1, -1));
        for (int u = 0; u < n; u++) up[u][0] = par[u];
        for (int j = 1; j <= lg; j++)
            for (int u = 0; u < n; u++)
                if (up[u][j-1] != -1) up[u][j] = up[up[u][j-1]][j-1];

        int sz = roots.size();
        vector<int> new_idx(n), treeSize(n, 0), h(n);
        // order[i] = x : node i thuộc về tree thứ x
        vector<int> order(n);
        vector<vector<vector<int>>> height(sz);
        // height[i][j] : vector chứa các nodes của cây thứ i có độ sâu j
        for (int i = 0; i < sz; i++) {
            int root = roots[i];
            int cnt = 0;
            function<void(int,int)> dfs = [&](int u, int p) {
                new_idx[u] = cnt++;
                order[u] = i;
                treeSize[u] = 1;
                for (auto v : adj[u]) {
                    if (v != p) {
                        dfs(v, u);
                        treeSize[u] += treeSize[v];
                    }
                }
            };
            dfs(root, -1);

            height[i].resize(treeSize[root]);
            height[i][0].push_back(new_idx[root]);
            h[root] = 0;

            function<void(int, int)> dfs2 = [&](int u, int p){
                for (auto v : adj[u]) {
                    if (v != p) {
                        h[v] = h[u] + 1;
                        height[i][h[v]].push_back(new_idx[v]);
                        dfs2(v, u);
                    }
                }
            };
            dfs2(root, -1);
        }

        int m; cin >> m;
        while (m--) {
            int v, p;
            cin >> v >> p;
            v--;
            int lo,hi;
            for (int j = 0; (1<<j) <= p && v != -1; j++)
                if (p >> j & 1) v = up[v][j];
            if (v == -1)
                cout << 0 << ' ';
            else {
                lo = new_idx[v];
                hi = new_idx[v] + treeSize[v] - 1;
                int i = order[v];
                int j = h[v] + p;
                vector<int>& a = height[i][j];
                int l = lower_bound(a.begin(), a.end(), lo) - a.begin();
                int r = upper_bound(a.begin(), a.end(), hi) - a.begin() - 1;
                cout << r-l << ' ';
            }
        }
    }
    return 0;
}