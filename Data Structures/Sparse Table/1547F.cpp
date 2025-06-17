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

template <typename T>
 struct SparseTable{
     vector <T> dp[32];
 
     /// defined for min by default, change as required
     T combine(const T& x, const T& y){
         return __gcd(x, y);
     }
 
     SparseTable(const vector<T> &ar){
         int i, j, l, h, n = (int)ar.size();
 
         dp[0] = ar;
         for (h = 1, l = 2; l <= n; h++, l <<= 1){
             dp[h].resize(n);
             for (i = 0, j = i + (l / 2); (i + l) <= n; i++, j++){
                 dp[h][i] = combine(dp[h - 1][i], dp[h - 1][j]);
             }
         }
     }
 
     T query(int l, int r){
         int h = __lg(r - l+1);
         return combine(dp[h][l], dp[h][r - (1 << h) + 1]);
     }
 };

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int m = n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        int gg = a[0];
        for (auto x : a) gg = __gcd(gg, x);
        for (auto& x : a) x /= gg;

        for (int i = 0; i < n-1; i++)
            a.push_back(a[i]);
        n = a.size();

        // lg : số lớn nhất thỏa mãn 2^lg < n
        int lg = __lg(n);
        // st[i][j] : gcd của 2^i phần tử tính từ phần tử j
        // vector<vector<int>> st(lg+1, vector<int>(n, 1));

        // for (int j = 0; j < n; j++) st[0][j] = a[j];
        // for (int i = 1; i <= lg; i++)
        //     for (int j = 0; j + (1<<i) <= n; j++)
        //         st[i][j] = __gcd(st[i-1][j], st[i-1][j + (1<<(i-1))]);

        SparseTable<int> st(a);

        int ans = 0; 
        for (int i = 0; i < m; i++) {
            for (int k = 0; k <= lg; k++) {
                // st[k][i] : 2^k phần tử kể từ phần i : [i, i + (1<<k) -1]
                // i + (1<<k) - 1 < n -> i + (1<<k) <= n
                if (st.dp[k][i] == 1) {
                    if (k>0) {
                        int cnt = 1ll << (k-1);
                        ans = max(ans, cnt);
                        int f = st.dp[k-1][i]; // [i, i + (1<<(k-1) -1)]
                        // left index : i + (1<<(k-1))
                        // right index : i + (1<<k) - 1
                        // gcd from left to right is decreasing
                        // -> binary search
                        int j = i + (1LL << (k-1));
                        int l = j;
                        int r = i + (1<<k) - 1;
                        while (l <= r) {
                            int mid = (l+r)/2;
                            int g = st.query(j,mid);
                            int len = mid - j + 1;
                            // int h = __lg(len);
                            // int g = __gcd(st[h][j], st[h][mid - (1<<h) + 1]);
                            g = __gcd(g, f);
                            if (g > 1) {
                                ans = max(ans, cnt + len);
                                l = mid+1;
                            } else {
                                r = mid-1;
                            }
                        }
                    }
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}