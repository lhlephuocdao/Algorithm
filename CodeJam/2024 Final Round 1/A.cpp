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
// 4=up-left, 5=down-right, 6=up-right, 7=down-left
int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

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

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        vector<vector<int>> sum(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                a[i][j] = s[j] - '0';
                sum[i][j] = a[i][j];
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (i>0) sum[i][j] += sum[i-1][j];
                if (j>0) sum[i][j] += sum[i][j-1];
                if (i>0 && j>0) sum[i][j] -= sum[i-1][j-1];
            }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++)
        //         cout << sum[i][j] << ' ';
        //     cout << '\n';
        // }

        vector<vector<bool>> used(n, vector<bool>(n, false));

        function<int(int,int,int,int)> getSum = [&](int x1, int y1, int x2, int y2) {
            // sum = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]
            assert(x1 <= x2);
            assert(y1 <= y2);
            int res = sum[x2][y2];
            if (y1>0) res -= sum[x2][y1-1];
            if (x1>0) res -= sum[x1-1][y2];
            if (x1>0 && y1>0) res += sum[x1-1][y1-1];
            return res;
        };

        function<void(int,int,int,int)> mark = [&](int x1, int y1, int x2, int y2){
            assert(y1 <= y2);
            assert(x1 <= x2);
            for (int i = x1; i <= x2; i++)
                for (int j = y1; j <= y2; j++)
                    used[i][j] = true;
        };

        function<void(int,int,int,int)> f = [&](int x1, int y1, int x2, int y2) {
            int d = x2 - x1 + 1;
            assert(x1 <= x2);
            assert(y1 <= y2);
            if (d==1) return;
            d /= 2;
            int total = getSum(x1, y1, x2, y2);
            assert(total <= sum[n-1][n-1]);
            int k = total % 4;
            if (k == 0) {
                // top-left
                mark(x1, y1, x1+d-1, y1+d-1);
                f(x1, y1+d, x1+d-1, y2);
                f(x1+d, y1, x2, y1+d-1);
                f(x1+d, y1+d, x2, y2);
            }
            else if (k == 1) {
                // top-right
                mark(x1, y1+d, x1+d-1, y2);
                f(x1, y1, x1+d-1, y1+d-1);
                f(x1+d, y1, x2, y1+d-1);
                f(x1+d, y1+d, x2, y2);
            }
            else if (k == 2) {
                // bottom-left
                mark(x1+d, y1, x2, y1+d-1);
                f(x1, y1, x1+d-1, y1+d-1);
                f(x1, y1+d, x1+d-1, y2);
                f(x1+d, y1+d, x2, y2);
            }
            else {
                // bottom - right
                mark(x1+d, y1+d, x2, y2);
                f(x1, y1, x1+d-1, y1+d-1);
                f(x1, y1+d, x1+d-1, y2);
                f(x1+d, y1, x2, y1+d-1);
            }
        };
        f(0,0,n-1,n-1);

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (used[i][j] == false)
                    ans += a[i][j];

        cout << ans << '\n';
    }

    return 0;
}