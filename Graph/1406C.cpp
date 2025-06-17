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

void debug(map<int, vector<int>>& m)
{
    for (auto v : m) {
        cout << v.first << " : ";
        for (auto x : v.second)
            cout << x << ' ';
        cout << '\n';
    }
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (int i = 0; i < n-1; i++)
        {
            int x,y;
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
            degree[x]++;
            degree[y]++;
        }

        int root;
        for (int i = 0; i < n; i++)
            if (degree[i] == 1) {
                root = i;
                break;
            }

        vector<int> size(n, 0);
        function<int(int, int)> dfs = [&](int u, int prev){
            size[u] = 1;
            for (auto v : adj[u]) {
                if (v != prev)
                    size[u] += dfs(v, u);
            }
            return size[u];
        };
        dfs(root, -1);
        // debug(size);

        map<int, vector<int>> m;

        function<void(int, int)> dfs2 = [&](int u, int prev){
            int max_size = size[root] - size[u];
            for (auto v : adj[u])
                if (v != prev)
                    max_size = max(max_size, size[v]);
            m[max_size].push_back(u);

            for (auto v : adj[u])
                if (v != prev)
                    dfs2(v, u);
        };

        dfs2(root, -1);
        // debug(m);

        if (m.begin()->second.size() == 1) {
            int x = 1;
            int y = adj[0][0] + 1;
            cout << x << ' ' << y << '\n';
            cout << x << ' ' << y << '\n';
        } else {
            vector<int>& v = m.begin()->second;
            int x = v[0];
            int y = v[1];
            int a;
            for (auto z : adj[x])
                if (size[z] > size[x]) {
                    a = z;
                    break;
                }
            cout << x+1 << ' ' << a+1 << '\n';
            cout << y+1 << ' ' << a+1 << '\n';
        }
    }
    return 0;
}