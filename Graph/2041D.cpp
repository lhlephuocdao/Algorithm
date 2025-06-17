#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

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

struct node {
    int x;
    int y;
    int dis;
    int dir;
    // 0 : up, 1 : left, 2 : down, 3 : right
    int count;
    bool operator<(const node& other) {
        return dis < other.dis;
    }
};

struct Compare {
    bool operator()(const node& a, const node& b) {
        return a.dis > b.dis; // Min-heap: Smaller `dis` has higher priority
    }
};

int32_t main()
{
    fastio;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        pii st, ed;
        vector<vector<char>> a(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S') st = {i, j};
                if (a[i][j] == 'T') ed = {i, j};
            }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        //          up, left, down, right
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        d[st.fi][st.se] = 0;
        priority_queue<node, vector<node>, Compare> pq;
        pq.push({st.fi, st.se, 0, -1, 0});

        while (!pq.empty())
        {
            node u = pq.top();
            pq.pop();

            if (u.dis != d[u.x][u.y]) continue;

            for (int i = 0; i < 4; i++)
            {
                int new_x = u.x + dx[i];
                int new_y = u.y + dy[i];
                if (new_x<0 || new_x>=n) continue;
                if (new_y<0 || new_y>=m) continue;
                if (a[new_x][new_y] == '#') continue;

                int new_count, new_dis;
                if (i == u.dir) new_count = u.count + 1;
                else new_count = 1;

                if (new_count <= 3)
                    new_dis = u.dis + 1;
                else {
                    new_dis = u.dis + 3;
                    new_count = 2;
                }

                if (new_dis < d[new_x][new_y]) {
                    cout << new_x << " " << new_y << " " << new_dis << " " << i << " " << new_count << '\n';
                    d[new_x][new_y] = new_dis;
                    pq.push({new_x, new_y, new_dis, i, new_count});
                }
            }
        }

        if (d[ed.fi][ed.se] != INT_MAX)
            cout << d[ed.fi][ed.se] << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}