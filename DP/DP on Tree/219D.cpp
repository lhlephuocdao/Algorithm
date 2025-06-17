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
    while (t--)
    {
        int n; cin >> n;
        vector<vector<pii>> adj(n);
        for (int i = 0; i < n-1; i++) {
            int u,v; // direction u -> v
            cin >> u >> v;
            u--; v--;
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        vector<int> a(n, 0), b(n, 0), c(n, 0);
        function<void(int, int)> dfs = [&](int u, int par){
            for (auto edge : adj[u]) {
                int v = edge.first;
                if (v == par) continue;
                bool is_down = edge.second == 1 ? true : false;
                if (is_down) {
                    a[v] = a[u] + 1;
                    b[v] = b[u];
                }
                else {
                    b[v] = b[u] + 1;
                    a[v] = a[u];
                }
                
                dfs(v, u);
                c[u] += c[v] + (is_down ? 0 : 1);
            }
        };
        dfs(0, -1);

        int ans = n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int ret = c[0] + a[i] - b[i];
            if (ret < ans) {
                ans = ret;
                s.clear();
                s.insert(i);
            } else if (ret == ans) {
                s.insert(i);
            }
        }

        cout << ans << '\n';
        for (auto it : s)
            cout << it+1 << ' ';
        cout << '\n';
    }
    return 0;
}