#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

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
        int n;
        cin >> n;
        vector<int> p(n+1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        vector<int> d(n);
        for (int i = 0; i < n; i++)
            cin >> d[i];

        vector<bool> visited(n+1, false);
        vector<int> c(n+1, 0), l;
        int id = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i]) {
                int u = i, len = 0;
                while (!visited[u]) {
                    visited[u] = true;
                    c[u] = id;
                    len++;
                    u = p[u];
                }
                l.push_back(len);
                id++;
            }
        }

        int ans = 0;
        int sz = l.size();
        vector<bool> choose(sz+1, false);
        for (int j = 0; j < n; j++) {
            int u = d[j];
            int idu = c[u];
            int lu = l[idu];
            if (choose[idu] == false) {
                ans += lu;
                choose[idu] = true;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }

    return 0;
}