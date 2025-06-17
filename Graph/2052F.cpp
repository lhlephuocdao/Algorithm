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
        int n; cin >> n;
        vector<vector<int>> a(2, vector<int>(n, 0));
        int cnt = 0;
        for (int i = 0; i < 2; i++)
        {
            string s; cin >> s;
            for (int j = 0; j < n; j++)
                if (s[j] == '.') {
                    a[i][j]++;
                    cnt++;
                }
        }

        if (cnt & 1) {
            cout << "None\n";
            continue;
        } else if (cnt == 0) {
            cout << "Unique\n";
            continue;
        }

        vector<vector<int>> adj(2*n);
        vector<int> deg(2*n, 0);
        for (int j = 0; j < n; j++) {
            if (a[0][j] || a[1][j] ) {
                // cout << "j: " << j << '\n';
                if (j+1 < n && a[0][j] && a[0][j+1]) {
                    adj[j].push_back(j+1);
                    adj[j+1].push_back(j);
                    deg[j]++;
                    deg[j+1]++;
                }

                if (j+1 < n && a[1][j] && a[1][j+1]) {
                    adj[n+j].push_back(n+j+1);
                    adj[n+j+1].push_back(n+j);
                    deg[n+j]++;
                    deg[n+j+1]++;
                }

                if (a[0][j] && a[1][j]) {
                    adj[j].push_back(n+j);
                    adj[n+j].push_back(j);
                    deg[j]++;
                    deg[n+j]++;
                }
            }
        }

        bool pos = true;
        for (int j = 0; j < n; j++) {
            // cout << "a[0][" << j+1 << ": " << a[0][j] << " deg: " << deg[j] << '\n';
            // cout << "a[1][" << j+1 << ": " << a[1][j] << " deg: " << deg[j+n] << '\n';
            if (a[0][j] && deg[j] == 0) pos = false;
            if (a[1][j] && deg[j+n] == 0) pos = false;
            if (!pos) break;
        }

        if (!pos) {
            cout << "None\n";
            continue;
        }

        // cout << "deg: \n";
        // for (auto x : deg) cout << x << ' ';
        // cout << '\n';

        queue<int> q;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] && deg[j + n*i] == 1)
                    q.push(j+n*i);

        if (q.empty()) {
            cout << "Multiple\n";
            continue;
        }

        vector<bool> removed(2*n, false);
        int done = 0;
        
        while (!q.empty()) {
            int u = q.front(); // u has degree = 1
            q.pop();
            if (deg[u] == 0) continue; // u has been removed by edge u-v previously
            if (adj[u].empty()) {
                pos = false;
                break;
            }
            int v = -1;
            for (auto x : adj[u]) {
                if (deg[x] != 0) {
                    v = x;
                    break;
                }
            }
            if (v == -1) {
                pos = false;
                break;
            }
            // cout << "v: " << v+1 << '\n';

            // remove edge u-v from graph
            done += 2;
            removed[u] = true;
            removed[v] = true;

            // cout << "remove edge: " << u+1 << " " << v+1 << '\n';
            
            for (auto x : adj[v]) {
                // decrease deg of adjcent of v
                if (deg[x]) deg[x]--;
                if (deg[v]) deg[v]--;
                // cout << "update deg[" << x+1 << "]: " << deg[x] << '\n';
                // cout << "removed[" << x+1 << "]: " << removed[x] << '\n';
                if (deg[x] == 1) q.push(x);
                if (deg[x] == 0 && removed[x] == false) {
                    pos = false;
                    break;
                }
            }

            if (!pos) break;
        }

        if (!pos) {
            cout << "None\n";
        } else {
            if (done == cnt)
                cout << "Unique\n";
            else
                cout << "Multiple\n";
        }
    }

    return 0;
}