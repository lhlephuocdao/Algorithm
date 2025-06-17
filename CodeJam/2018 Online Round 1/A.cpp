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

    int t = 1;
    while (t--)
    {
        string S; cin >> S;
        int len = S.length();
        int n,m; cin >> n >> m;
        vector<string> table(n);
        for (auto& s : table) cin >> s;

        bool check = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char s = table[i][j];
                if (s != S[0]) continue;

                for (int d = 0; d < 8; d++) {
                    int idx = 1;
                    int x = i, y = j;
                    while (idx < len) {
                        x = x + dx[d];
                        y = y + dy[d];
                        if (x < 0 || x >= n) break;
                        if (y < 0 || y >= m) break;
                        if (table[x][y] != S[idx]) break;
                        idx++;
                    }
                    if (idx == len) {
                        check = true;
                        break;
                    }
                }

                if (check) break;
            }
            if (check) break;
        }

        cout << check ? 1 : 0 << '\n';
    }

    return 0;
}