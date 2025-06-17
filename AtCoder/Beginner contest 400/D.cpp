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
        int h,w;
        cin >> h >> w;
        vector<string> a(h);
        for (auto& x : a)
            cin >> x;
        int sx,sy,ex,ey;
        cin >> sx >> sy >> ex >> ey;
        sx--, sy--;
        ex--, ey--;

        priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
        vector<vector<int>> d(h, vector<int>(w, INT_MAX));
        d[sx][sy] = 0;
        pq.push({0, {sx, sy}});

        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            int dis = node.fi;
            int x = node.sc.fi;
            int y = node.sc.sc;

            if (dis > d[x][y]) continue;

            for (int i = 0; i < 4; i++) {
                // 1 step
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || nx >= h) continue;
                if (ny < 0 || ny >= w) continue;

                bool check = false;
                int new_dis = dis;
                if (a[nx][ny] == '#') {
                    new_dis++;
                    check = true;
                }
                if (new_dis < d[nx][ny]) {
                    d[nx][ny] = new_dis;
                    pq.push({new_dis, {nx, ny}});
                }

                // 2 steps
                nx += dx[i];
                ny += dy[i];
                if (nx < 0 || nx >= h) continue;
                if (ny < 0 || ny >= w) continue;

                new_dis = dis;
                if (check || a[nx][ny] == '#') new_dis++;
                if (new_dis < d[nx][ny]) {
                    d[nx][ny] = new_dis;
                    pq.push({new_dis, {nx, ny}});
                }
            }
        }

        cout << d[ex][ey] << '\n';
    }
    return 0;
}