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
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& x : v) cin >> x;
        int lg = __lg(n-1);
        vector<vector<int>> st(lg+1, vector<int>(n, 0));
        vector<vector<int>> st2(lg+1, vector<int>(n, 0));

        for (int j = 0; j < n; j++) st[0][j] = v[j], st2[0][j] = v[j];
        for (int i = 1; i <= lg; i++)
            for (int j = 0; j + (1<<i) <= n; j++) {
                st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
                st2[i][j] = max(st2[i-1][j], st2[i-1][j + (1 << (i-1))]);
            }

        int l = 0, r = n-1;
        int x = -1, y = -1, z = -1;
        bool check = false;
        while (l < r-1) {
            int i = __lg(l+1);
            int j = __lg(n-r);
            int a = max(st2[i][0], st2[i][l - (1<<i) + 1]);
            int b = max(st2[j][r], st2[j][n-1 - (1<<j) + 1]);

            int k = __lg(r-l-1); // [l+1, r-1]
            int c = min(st[k][l+1], st[k][r-1 - (1<<k) + 1]);

            if (a > b) r--;
            else if (a < b) l++;
            else {
                if (a == c) {
                    check = true;
                    x = l+1;
                    y = r-l-1;
                    z = n-r;
                    break;
                } else if (c > a) {
                    l++;
                    r--;
                } else {
                    bool has = false;
                    if (v[l+1] < a) l++, has = true;
                    if (v[r-1] < b) r--, has = true;
                    if (!has) {
                        // c < a = b
                        // v[l+1] = a and v[r-1] = b
                        // -> cần tìm vị trí gần nhất trong đoạn [l+1, r-1] mà < a,b -> take it
                        int i = l+1, j = r-1;
                        while (i<r-1 && v[i] == a) i++;
                        while (j>l+1 && v[j] == b) j--;
                        if (v[i] < a || v[j] < b) {
                            if (v[i] < a) l=i;
                            else if (v[j] < b) r=j;
                        } else {
                            l=i;
                            r=j;
                        }
                    }
                }
            }
        }

        if (check) {
            cout << "YES\n";
            cout << x << ' ' << y << ' ' << z << '\n';
        } else cout << "NO\n";
    }
    return 0;
}