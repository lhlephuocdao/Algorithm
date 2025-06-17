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

struct LCA {
    vector<int> height, euler, first;
    vector<bool> visited;
    int n, lg;
    vector<vector<int>> st;
 
    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        sparseTable();
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void sparseTable() {
        int m = euler.size();
        lg = __lg(m);
        // st[i][j] : index của euler tour ứng với node có height nhỏ nhất của 2^i phần tử kể từ phần tử thứ j
        st.assign(lg+1, vector<int>(m, INT_MAX));

        for (int j = 0; j < m; j++) st[0][j] = j;
        for (int i = 1; i <= lg; i++)
            for (int j = 0; j + (1<<i) <= m; j++) {
                int a = st[i-1][j];
                int b = st[i-1][j + (1<<(i-1))];
                st[i][j] = (height[euler[a]] < height[euler[b]]) ? a : b;
            }
    }

    int query(int u, int v) {
        int l = first[u], r = first[v];
        if (l > r)
            swap(l, r);
        int k = __lg(r-l+1);
        int a = st[k][l];
        int b = st[k][r - (1ll<<k) + 1];
        return (height[euler[a]] < height[euler[b]]) ? euler[a] : euler[b];
    }
};

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n; cin >> n;
        vector<vector<int>> adj(n);
        int root = -1;
        vector<bool> is_root(n, true);
        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                x--;
                adj[i].push_back(x);
                adj[x].push_back(i);
                is_root[x] = false;
            }
        }

        for (int i = 0; i < n; i++)
            if (is_root[i]) {
                root = i;
                break;
            }

        LCA tree(adj, root);
        int q; cin >> q;
        cout << "Case " << tc << ":\n";
        while (q--) {
            int u,v;
            cin >> u >> v;
            u--, v--;
            int k = tree.query(u, v);
            cout << k+1 << '\n';
        }
    }
    return 0;
}