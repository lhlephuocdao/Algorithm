#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;
const int INF = 1e18;

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
        int n,m; cin >> n >> m;
        vector<int> x(n), y;
        vector<bool> used(2*n+1, false);
        for (auto& v : x) cin >> v, used[v + n] = true;
        for (int i = 0; i < 2*n+1; i++)
            if (i!=n && used[i] == false)
                y.push_back(i-n);

        // for (auto v : y) cout << v << ' ';
        // cout << '\n';

        assert(y.size() == n);
        /*
            dp[i][S] : số cách để đạt i points với subset S của Bob's card

            dp[i][S] = tổng của dp[i-1][S \ {j}] với j thuộc S và Y[j], X[k-1] thỏa mãn điều kiện để Albert có điểm
            (k là số bit 1 trong tập S, j từ 0 tới 14)
            HOẶC:
            dp[i][S] = tổng của dp[i][S \ {j}] với j thuộc S và Y[j], X[k-1] KHÔNG thỏa mãn đk Albert có điểm

            dp[0][0] = 1 : Có 1 cách để Albert có 0 điểm từ tập rỗng.
        */
        vector<vector<int>> dp(n+1, vector<int>(1ll<<n, 0));
        dp[0][0] = 1;

        for (int s = 1; s < (1ll << n); s++) { // duyệt qua tất cả các tập con của Bob's card
            int k = __builtin_popcount(s); // số bit 1 trong tập s

            for (int j = 0; j < n; j++) { // duyệt qua tất cả các phần tử trong tập S
                if (s & (1ll << j)) { // Nếu phần tử j thuộc tập S
                    for (int i = 0; i <= min(m, k); i++) { // duyệt qua số điểm i có thể có của Albert
                        // Nếu Albert có điểm từ Y[j] và X[k-1]
                        if (x[k-1]*y[j] < 0 || abs(x[k-1]) > abs(y[j])) {
                            if (i>0) dp[i][s] += dp[i-1][s ^ (1ll << j)];
                        } else {
                            dp[i][s] += dp[i][s & ~(1ll << j)];
                        }
                    }
                }
            }
        }

        cout << dp[m][(1ll<<n) - 1] << '\n';
    }
    return 0;
}