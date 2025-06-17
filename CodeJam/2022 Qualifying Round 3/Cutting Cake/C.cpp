#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>
const int mod = 1e9 + 7;

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
    cin >> t;
    while (t--)
    {
        int r,c,n;
        cin >> r >> c >> n;
        // S=0, B=1, R=2
        vector<vector<vector<int>>> fruit(3, vector<vector<int>>(r, vector<int>(c, 0)));
        vector<string> cake(r);
        for (int i = 0; i < r; i++) {
            cin >> cake[i];
            for (int j = 0; j < c; j++) {
                if (cake[i][j] == 'S') fruit[0][i][j] = 1;
                else if (cake[i][j] == 'B') fruit[1][i][j] = 1;
                else if (cake[i][j] == 'R') fruit[2][i][j] = 1;
            }
        }
        string fri; cin >> fri;

        for (int i = 0; i < 3; i++)
            for (int x = 0; x < r; x++)
                for (int y = 0; y < c; y++)
                {
                    if (y>0) fruit[i][x][y] += fruit[i][x][y-1];
                    if (x>0) fruit[i][x][y] += fruit[i][x-1][y];
                    if (x>0 && y>0) fruit[i][x][y] -= fruit[i][x-1][y-1];
                }

        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(n, -1)));

        function<bool(int,int,int,int,int)> check = [&](int x1, int y1, int x2, int y2, int k){
            // Còn k lần cắt -> lần cắt này dành cho người thứ n-k-1
            // Check xem người thứ n-k-1 cần toping gì ?
            int i = n-k-1;
            int topping = fri[i] == 'S' ? 0 : (fri[i] == 'B' ? 1 : 2);
            // Check hcn (x1,y1)->(x2,y2) có topping cần tìm k
            int cnt = fruit[topping][x2][y2];
            if (y1>0) cnt -= fruit[topping][x2][y1-1];
            if (x1>0) cnt -= fruit[topping][x1-1][y2];
            if (x1>0 && y1>0) cnt += fruit[topping][x1-1][y1-1];

            return cnt > 0;
        };

        function<int(int,int,int)> cal = [&](int x, int y, int k){
            if (dp[x][y][k] != -1) return dp[x][y][k];

            if (k == 0) {
                // cần check xem miếng bánh từ (x,y)->(r-1,c-1) có thỏa mãn người thứ N k
                dp[x][y][k] = check(x,y,r-1,c-1,k) ? 1 : 0;
                return dp[x][y][k];
            }

            dp[x][y][k] = 0;
            // Cắt theo chiều ngang
            for (int i = x; i <= r-2; i++) {
                if (check(x,y,i,c-1,k) == false) continue;
                dp[x][y][k] += cal(i+1, y, k-1);
                dp[x][y][k] %= mod;
            }

            // Cắt theo chiều dọc
            for (int j = y; j <= c-2; j++) {
                if (check(x,y,r-1,j,k) == false) continue;
                dp[x][y][k] += cal(x, j+1, k-1);
                dp[x][y][k] %= mod;
            }
            return dp[x][y][k];
        };

        cal(0, 0, n-1);
        cout << dp[0][0][n-1] << '\n';
    }

    return 0;
}