#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

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
    // cin >> t;
    while (t--)
    {   
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        vector<int> in(n, 0), topo;
        queue<int> q;

        while (m--) {
            int a,b;
            cin >> a >> b;
            a--, b--;
            g[a].push_back(b);
            in[b]++;
        }

        for (int i = 0; i < n; i++)
            if (!in[i])
                q.push(i);

        while (q.empty() == false) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto v : g[u]) {
                in[v]--;
                if (!in[v]) q.push(v);
            }
        }

        if (topo.size() < n) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (auto x : topo) cout << x+1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}