#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;
const int INF = 1e9;

int R, C, K;
int X[MAXN], Y[MAXN];
bool blocked[MAXN][MAXN], marked[MAXN][MAXN];
int dp[MAXN][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        blocked[x][y] = true;
    }
    int x0, y0;
    cin >> x0 >> y0;
    x0--; y0--;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!blocked[i][j]) {
                bool valid = true;
                if (j % 2 == y0 % 2 && (i == x0 || i == x0 - 1 || i == x0 + 1)) {
                    valid = false;
                }
                if (valid) {
                    marked[i][j] = true;
                }
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int j = 0; j < C; j++) {
        for (int i = 0; i < R; i++) {
            if (!marked[i][j]) {
                continue;
            }
            if (dp[i][j % 2] != -1) {
                dp[i][1 - j % 2] = max(dp[i][1 - j % 2], dp[i][j % 2]);
                if (j % 2 == 0) {
                    if (i > 0 && marked[i - 1][j + 1]) {
                        dp[i - 1][1 - j % 2] = max(dp[i - 1][1 - j % 2], dp[i][j % 2] + 1);
                    }
                    if (i < R - 1 && marked[i + 1][j + 1]) {
                        dp[i + 1][1 - j % 2] = max(dp[i + 1][1 - j % 2], dp[i][j % 2] + 1);
                    }
                } else {
                    if (i > 0 && marked[i - 1][j - 1]) {
                        dp[i - 1][1 - j % 2] = max(dp[i - 1][1 - j % 2], dp[i][j % 2] + 1);
                    }
                    if (i < R - 1 && marked[i + 1][j - 1]) {
                        dp[i + 1][1 - j % 2] = max(dp[i + 1][1 - j % 2], dp[i][j % 2] + 1);
                    }
                }
            }
        }
        memset(dp, -1, sizeof(dp));
    }
    int ans = -INF;
    for (int i = 0; i < R; i++) {
        ans = max(ans, dp[i][C % 2]);
    }
    cout << ans << "\n";
    return 0;
}
