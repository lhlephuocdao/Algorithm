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
    cin >> t;
    while (t--)
    {
        int n, st, en;
        cin >> n >> st >> en;

        vector<vector<int>> tree(n + 1);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<int> deep(n+1, 0);
        vector<vector<int>> d(n+1);

        function<void(int, int)> dfs = [&](int u, int prev){
            for (auto v : tree[u]) {
                if (v != prev) {
                    deep[v] = deep[u] + 1;
                    d[deep[v]].push_back(v);
                    dfs(v, u);
                }
            }
        };

        d[0].push_back(en);
        dfs(en, 0);

        for (int i = n; i >= 0; i--){
            for (auto x : d[i])
                cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}


    