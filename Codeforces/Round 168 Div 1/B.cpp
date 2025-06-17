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
    while (tc--)
    {
        int n; cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n-1; i++) {
            int u,v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> a(n);
        for (auto& x : a) cin >> x;

        function<pii(int,int)> dfs = [&](int u, int par){
            // maxi : maximum number of increase opeartions
            // maxd : maximum number of decrease operations
            int maxi = 0, maxd = 0;
            for (auto v : g[u]) {
                if (v == par) continue;
                auto [p1, p2] = dfs(v, u);
                maxi = max(maxi, p1);
                maxd = max(maxd, p2);
            }

            // value of v[u] after doing both these 2 operations
            a[u] += maxi;
            a[u] -= maxd;
            
            if (a[u] > 0) maxd += a[u];
            else maxi += -a[u];

            // cout << "u : " << u << " maxi : " << maxi << " maxd : " << maxd << '\n';

            return make_pair(maxi, maxd);
        };
        auto [x1, x2] = dfs(0, -1);
        cout << x1 + x2 << '\n';
    }

    return 0;
}