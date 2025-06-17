#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define pii pair<int, int>
#define int long long

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s;
        cin >> s;
        s = ' ' + s;
        vector<int> p(n+1);
        vector<vector<int>> adj(n+1);
        int root;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            if (p[i] == 0) root = i;
            // p[i] is the parent of i
            adj[p[i]].push_back(i);
            adj[i].push_back(p[i]);
        }

        vector<pair<pii, pii>> dp(n+1, {{0, 0}, {0, 0}});
        // dp[i].first.first = longest nice simple path starting at i
        // dp[i].first.second = number of longest nice simple path starting at i

        // dp[i].second.first = longest nice simple path of a subtree rooted at i
        // dp[i].second.second = number of longest nice simple path of a subtree rooted at i

        function<void(int, int)> dfs = [&](int u, int prev){
            bool is_leaf = true;
            int max1 = 0, max2 = 0, cnt2 = 0;
            int num_max1 = 0; // số path con có len = max1
            int tot = 0, sum_sq = 0;
            // tot : number of longest nice simple path
            // tot = (a + b + c + ...)
            // sum_sq : a*a + b*b + c*c + ...
            //max1 : longest nice simple path starting at children of u
            //max2 : second longest nice simple path starting at children of u
            // cnt2: number of second longest nice simple path starting at children of u
            for (auto v : adj[u]) {
                if (v == prev) continue;
                dfs(v, u);
                if (s[u] != s[v]) {
                    is_leaf = false;
                    int x = dp[v].first.first; // start at v
                    int cnt_x = dp[v].first.second; // number of starting at v

                    if (max1 == 0 && max2 == 0) { // first child node of u
                        max1 = x;
                        num_max1 = 1;
                        tot = cnt_x;
                        sum_sq = cnt_x * cnt_x;
                    } else {
                        if (x > max1) {
                            max2 = max1;
                            cnt2 = tot;
                            max1 = x;
                            num_max1 = 1;
                            tot = cnt_x;
                            sum_sq = cnt_x * cnt_x;
                        } else if (x == max1) {
                            num_max1++;
                            tot += cnt_x;
                            sum_sq += cnt_x * cnt_x;
                        } else if (x > max2) {
                            max2 = x;
                            cnt2 = cnt_x;
                        } else if (x == max2) {
                            cnt2 += cnt_x;
                        }
                    }
                }
            }

            if (is_leaf) {
                dp[u] = {{1, 1}, {1, 1}};
                return;
            }

            if (num_max1 >= 2) {
                int tmp = (tot*tot - sum_sq)/2;
                dp[u] = {{max1+1, tot}, {2*max1 + 1, tmp}};
            } else {
                //tot = 1 and cnt2 = 0
                if (cnt2 == 0)
                    dp[u] = {{max1+1, tot}, {max1+1, tot}};
                else
                //tot = 1 and cnt2 >= 1
                    dp[u] = {{max1+1, tot}, {max1 + max2 + 1, tot*cnt2}};
            }

        };

        dfs(root, 0);

        int ans = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int y = dp[i].second.first; // longest
            int z = dp[i].second.second; // count

            if (y > ans) {
                ans = y;
                cnt = z;
            } else if (y == ans) {
                cnt += z;
            }
        }

        cout << ans << " " << cnt << '\n';
    }
    return 0;
}