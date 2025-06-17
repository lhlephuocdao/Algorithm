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
 
    int t = 1; cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++) {
            int u,v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int xr = 0;
        for (auto& x : a) xr ^= x;

        if (xr == 0) {
            cout << "YES\n";
        } else {
            int y = xr;
            int cnt = 0; // số connected components mà có xor = y

            function<int(int,int)> dfs = [&](int u, int par) {
                int s = a[u];
                for (auto v : adj[u]) {
                    if (cnt == 2) return s;
                    if (v == par) continue;
                    int tmp = dfs(v, u);
                    if (tmp == y && cnt < 2)
                        cnt++;
                    else
                        s ^= tmp;
                }
                return s;
            };
            dfs(0, -1);

            if (cnt == 2 && k > 2) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}