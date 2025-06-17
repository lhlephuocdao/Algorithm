#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<int>& a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++)
        {
            int u,v;
            cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> sz(n, 1);
        function<int(int, int)> dfs1 = [&](int u, int prev){
            for (auto v : adj[u]) {
                if (v != prev) {
                    sz[u] += dfs1(v, u);
                }
            }
            return sz[u];
        };

        dfs1(0, -1);
        // debug(sz);

        function<int(int, int&, int, int)> dfs2 = [&](int x, int& cnt, int u, int prev) {
            if (sz[u] < x || cnt == k) return 0ll;
            
            if (sz[u] == x) {
                cnt++;
                return sz[u];
            }        

            int sub = 0;
            for (auto v : adj[u]) {
                if (v != prev) {
                    sub += dfs2(x, cnt, v, u);
                }
            }
            int ns_u = sz[u] - sub;
            if (ns_u >= x && cnt < k) {
                cnt++;
                return sz[u];
            } else return sub;
        };

        int low = 1, high = n/(k+1);
        int ans = 0;
        while (low <= high)
        {
            int mid = (low + high)/2;
            int cnt = 0;
            int remain = sz[0] - dfs2(mid, cnt, 0, -1);
            if (cnt >= k && remain >= mid) {
                ans = max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}