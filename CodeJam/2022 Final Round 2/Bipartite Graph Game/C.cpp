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
        int n,m,k;
        cin >> n >> m >> k;
        vector<pii> edge(k);
        vector<int> mx(n, 0), my(m, 0);

        for (int i = 0; i < k; i++){
            int a,b;
            cin >> a >> b;
            a--; b--;
            edge[i] = {a, b};
            mx[a]++;
            my[b]++;
        }
        
        vector<pii> x, y; // {cnt, node}
        for (int i = 0; i < n; i++)
            x.push_back({mx[i], i});
        for (int j = 0; j < m; j++)
            y.push_back({my[j], j});

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int ans1 = 0, ans2 = 0;
        vector<int> vx(n), vy(m);
        // vx[i] : value assigns to node i
        // vy[j] : value assigns to node j
        int dx = x.back().first; // max degree of a node on X
        int dy = y.back().first; // max degree of a node on Y
        vector<int> minx(dx+1, 0), miny(dy+1, 0);
        // minx[i] : min value assign to a node which has i degree
        // miny[j] : min value assign to a node which has j degree
        for (int i = 0; i < n; i++) {
            vx[x[i].second] = i+1;
            if (minx[x[i].first] == 0) minx[x[i].first] = i+1;
            ans1 += x[i].first * (i+1);
        }

        for (int j = 0; j < m; j++) {
            vy[y[j].second] = j+1;
            if (miny[y[j].first] == 0) miny[y[j].first] = j+1;
            ans1 += y[j].first * (j+1);
        }

        for (int i = 0; i < k; i++) {
            int a = edge[i].first;
            int b = edge[i].second;
            int da = mx[a];
            int db = my[b];
            int y = minx[da] + miny[db];
            ans2 = max(ans2, ans1 - y);
        }

        cout << ans1 << " " << ans2 << '\n';
    }

    return 0;
}