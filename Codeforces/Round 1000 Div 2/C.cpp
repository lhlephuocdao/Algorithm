#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 998244353;

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

 void debug(vector<pair<int, int>>& a)
 {
     for (auto x : a)
     {
        cout << x.first << " " << x.second << '\n';
     }
 }

int32_t main()
{
    fastio;

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<pair<int, int>> deg(n); // {cnt, index}
        for (int i = 0; i < n; i++)
            deg[i] = {0, i};

        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);

            deg[u].first++;
            deg[v].first++;
        }

        
        int ans = 0;
        sort(deg.begin(), deg.end());
        // debug(deg);
        
        int m1 = deg.back().first, v1 = deg.back().second;
        deg.pop_back();

        // cout << "m1: " << m1 << " v1: " << v1 << '\n';

        int cnt = 1;
        int idx = deg.size()-1;
        while (idx >= 0 && deg[idx].first == m1) cnt++, idx--;

        if (cnt <= 2) {
            ans += m1;
            sort(adj[v1].begin(), adj[v1].end());
            vector<bool> sub(n, false);
            for (auto x : adj[v1]) {
                sub[x] = true;
                // cout << "remove " << x << '\n';
                adj[x].erase(find(adj[x].begin(), adj[x].end(), v1));
            }

            for (int i = 0; i < n-1; i++) {
                int v = deg[i].second;
                if (sub[v]) deg[i].first--;
            }

            sort(deg.begin(), deg.end());

            int m2 = deg.back().first, v2 = deg.back().second;
            // cout << "m2: " << m2 << " v2: " << v2 << '\n';

            ans += deg.back().first - 1;
        } else {
            ans += 2*m1 - 1;
        }

        cout << ans << '\n';
    }
    return 0;
}