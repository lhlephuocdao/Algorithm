#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 1000003;
 
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
 
    int t = 1; cin >> t;
    while (t--)
    {
        int R,C,N,r,c;
        cin >> R >> C >> N >> r >> c;
        r--, c--;
        vector<pii> pawns(N);
        for (int i = 0; i < N; i++) {
            int x,y;
            cin >> x >> y;
            x--, y--;
            pawns[i] = {x, y};
        }

        vector<string> grid(R);
        for (int i = 0; i < R; i++)
            cin >> grid[i];

        vector<vector<int>> d(R, vector<int>(C, INT_MAX));
        d[r][c] = 0;
        queue<pii> q;
        q.push({r, c});
        vector<vector<bool>> visited(R, vector<bool>(C, false));

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if (new_x < 0 || new_x >= R) continue;
                if (new_y < 0 || new_y >= C) continue;
                if (grid[new_x][new_y] == '.' && visited[new_x][new_y] == false) {
                    d[new_x][new_y] = d[x][y] + 1;
                    visited[new_x][new_y] = true;
                    q.push({new_x, new_y});
                } else if (grid[new_x][new_y] == 'W') {
                    d[new_x][new_y] = min(d[new_x][new_y], d[x][y] + 1);
                }
            }
        }

        int D = 0;
        for (int i = 0; i < N; i++)
            D += d[pawns[i].first][pawns[i].second];

        vector<vector<vector<int>>> dis(N, vector<vector<int>>(R, vector<int>(C, INT_MAX)));
        // dis[i][x][y] : shortest distance từ pawn[i] đến wall tại {x, y}
        for (int i = 0; i < N; i++) {
            dis[i][pawns[i].first][pawns[i].second] = 0;
            queue<pii> que;
            que.push({pawns[i].first, pawns[i].second});
            vector<vector<bool>> vis(R, vector<bool>(C, false));
            while (!que.empty()) {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();
                vis[x][y] = true;

                for (int j = 0; j < 4; j++) {
                    int new_x = x + dx[j];
                    int new_y = y + dy[j];
                    if (new_x < 0 || new_x >= R) continue;
                    if (new_y < 0 || new_y >= C) continue;

                    if (grid[new_x][new_y] == '.' && vis[new_x][new_y] == false) {
                        dis[i][new_x][new_y] = dis[i][x][y] + 1;
                        vis[new_x][new_y] = true;
                        que.push({new_x, new_y});
                    } else if (grid[new_x][new_y] == 'W') {
                        dis[i][new_x][new_y] = min(dis[i][new_x][new_y], dis[i][x][y] + 1);
                    }
                }
            }
        }

        int Net = 0;
        for (int x = 0; x < R; x++)
            for (int y = 0; y < C; y++)
                if (grid[x][y] == 'W') {
                    for (int i = 0; i < N; i++) {
                        int px = pawns[i].first;
                        int py = pawns[i].second;
                        // origin : d[px][py]
                        // changed: d[x][y] + dis[i][x][y]
                        // Net = origin - changed
                        Net += max(d[px][py] - (d[x][y] + dis[i][x][y]), 0ll);
                    }
                }

        cout << D << ' ' << Net << '\n';
    }
    return 0;
}