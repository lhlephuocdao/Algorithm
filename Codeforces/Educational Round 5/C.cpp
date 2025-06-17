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

struct DSU {
    vector<vector<pii>> parent;
    vector<vector<int>> sz;
 
    DSU(int n, int m) {
        parent.resize(n, vector<pii>(m));
        sz.resize(n, vector<int>(m, 0));
    };
 
    void make_set(pii p) {
        parent[p.fi][p.sc] = p;
        sz[p.fi][p.sc] = 1;
    }
 
    pii find_set(pii p) {
        return p == parent[p.fi][p.sc] ? p : parent[p.fi][p.sc] = find_set(parent[p.fi][p.sc]);
    }
 
    void join_sets(pii a, pii b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a.fi][a.sc] < sz[b.fi][b.sc]) {
                swap(a,b);
            }
            parent[b.fi][b.sc] = a;
            sz[a.fi][a.sc] += sz[b.fi][b.sc];
        }
    }
};

int32_t main()
{
    fastio;

    int t = 1;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<char>> c(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> c[i][j];

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        DSU g(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (c[i][j] == '.') g.make_set({i, j});
                    
        function<void(int,int)> bfs = [&](int u, int v){
            queue<pii> q;
            q.push({u,v});

            while (!q.empty()) {
                auto node = q.front();
                q.pop();

                int x = node.fi;
                int y = node.sc;
                visited[x][y] = true;

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= n) continue;
                    if (ny < 0 || ny >= m) continue;
                    if (visited[nx][ny] || c[nx][ny] == '*') continue;

                    g.join_sets({x, y}, {nx, ny});
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        };

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (visited[i][j] == false && c[i][j] == '.')
                    bfs(i, j);

        vector<string> ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (c[i][j] == '.')
                    ans[i] += '.';
                else {
                    int res = 1;
                    pii up = {i-1, j};
                    pii down = {i+1, j};
                    pii left = {i, j-1};
                    pii right = {i, j+1};

                    set<pii> st;
                    if (i-1 >= 0 && c[i-1][j] == '.') up = g.find_set({up.fi, up.sc}), st.insert(up);
                    if (i+1 < n && c[i+1][j] == '.') down = g.find_set({down.fi, down.sc}), st.insert(down);
                    if (j-1 >= 0 && c[i][j-1] == '.') left = g.find_set({left.fi, left.sc}), st.insert(left);
                    if (j+1 < m && c[i][j+1] == '.') right = g.find_set({right.fi, right.sc}), st.insert(right);

                    for (auto itr : st) {
                        res += g.sz[itr.first][itr.second];
                        res %= 10;
                    }

                    ans[i] += char(res + '0');
                }
            }
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << '\n';
    }
    return 0;
}