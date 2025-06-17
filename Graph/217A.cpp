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

struct Point {
    int x;
    int y;
};

int32_t main()
{
    fastio;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<Point> p(n);
        vector<vector<int>> c(1001), r(1001);
        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
            c[p[i].x].push_back(p[i].y);
            r[p[i].y].push_back(p[i].x);
        }

        vector<vector<bool>> visited(1001, vector<bool>(1001, false));

        function<void(int, int)> dfs = [&](int x, int y){
            visited[x][y] = true;
            for (auto col : r[y]) {
                if (visited[col][y] == false)
                    dfs(col, y);
            }

            for (auto row : c[x])
                if (visited[x][row] == false)
                    dfs(x, row);
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = p[i].x;
            int y = p[i].y;
            if (visited[x][y] == false) {
                dfs(x, y);
                ans++;
            }
        }
        cout << ans-1 << '\n';
    }
    return 0;
}