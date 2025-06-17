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
        int n;
        string x; 
        cin >> n >> x;
        int m = x.length();
        vector<int> v(n);
        for (auto& i : v) cin >> i, i--;

        struct point {
            int s = 0;
            int p = 0;
            int sign = 0;
        };
        int max_size = 1<<(m-1);
        vector<point> ans;

        function<void(int,int,int,int)> back = [&](int curSum, int s, int k, int sign){
            if (k == m) {
                curSum += s;
                ans.push_back({curSum, __builtin_popcount(sign), sign});
                return;
            }

            // empty
            back(curSum, s*10+(x[k]-'0'), k+1, sign);

            // '+'
            int new_sign = sign | (1<<(m-1-k));
            back(curSum+s, x[k]-'0', k+1, new_sign);
        };
        back(0, x[0]-'0', 1, 0);

        sort(ans.begin(), ans.end(), [&](point& a, point& b){
            if (a.s != b.s) return a.s < b.s;
            else return a.sign > b.sign;
        });

        int Ws = 0, Wp = 0;
        for (int i = 0; i < n; i++) {
            Ws += ans[v[i]].s;
            Wp += ans[v[i]].p;
        }
        cout << Ws << " " << Wp << '\n';
    }

    return 0;
}