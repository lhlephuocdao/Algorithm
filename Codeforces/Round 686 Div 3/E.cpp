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
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            int u,v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        vector<int> cycle, s;
        bool found = false;
        function<void(int,int)> dfs1 = [&](int u, int prev){
            visited[u] = true;
            s.push_back(u);
            for (auto v : adj[u]) {
                if (found) return;
                if (v == prev) continue;
                if (visited[v] == false)
                    dfs1(v, u);
                else {
                    found = true;
                    for (int i = s.size()-1; i >= 0; i--) {
                        cycle.push_back(s[i]);
                        if (s[i] == v) break;
                    }
                }
            }
            s.pop_back();
        };
        dfs1(0, -1);

        vector<bool> is_cycle(n, false);
        for (auto x : cycle) is_cycle[x] = true;
        int sz = cycle.size();

        vector<pii> dp(n, {0,0});
        // dp[i] = {x,y}
        // x : số simple paths xuất phát từ i
        // y : số simple paths của substree rooted tại i
        function<void(int, int)> dfs = [&](int u, int prev){
            int total = 0, sum = 0;
            for (auto v : adj[u]) {
                if (v == prev || is_cycle[v]) continue;
                dfs(v,u);

                dp[u].first += dp[v].first + 1;
                dp[u].second += dp[v].second + dp[v].first + 1;

                total += dp[v].first + 1;
                sum += (dp[v].first+1)*(dp[v].first+1);
            }
            dp[u].second += (total*total - sum)/2;
        };

        for (int i = 0; i < n; i++)
            if (is_cycle[i])
                dfs(i, -1);

        int total = 0, sum = 0;
        for (int i = 0; i < n; i++)
            if (is_cycle[i]) {
                total += dp[i].first;
                sum += dp[i].first * dp[i].first;
            }

        int ans = sz*(sz-1) + total*total - sum;
        for (int i = 0; i < n; i++)
            if (is_cycle[i]) {
                ans += 2*(sz-1)*dp[i].first;
                ans += dp[i].second;
            }

        cout << ans << '\n';
    }
    return 0;
}