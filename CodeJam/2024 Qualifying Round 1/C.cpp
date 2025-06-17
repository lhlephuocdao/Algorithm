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
// 4=up-left, 5=down-right, 6=up-right, 7=down-left
int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

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

    const int maxn = 1e5;
    vector<vector<int>> C(maxn+1, vector<int>(3));
    for (int i = 0; i <= maxn; i++){
        C[i][0] = 1;
        for (int k = 1; k <= min(i, 2ll); k++){
            C[i][k] = C[i - 1][k - 1] + C[i - 1][k];
        }
    }

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n; cin >> n;
        vector<int> L(n+1), R(n+1);
        for (int i = 1; i <= n; i++) cin >> L[i];
        for (int i = 1; i <= n; i++) cin >> R[i];
        vector<vector<int>> g(n+1);
        vector<int> roots;
        vector<bool> check(n+1, false);
        for (int i = 1; i <= n; i++) {
            g[i].push_back(L[i]);
            g[i].push_back(R[i]);
            check[L[i]] = true;
            check[R[i]] = true;
        }

        for (int i = 1; i <= n; i++)
            if (check[i] == false) roots.push_back(i);

        if (roots.size() != 1) {
            cout << 0 << '\n';
            continue;
        }

        int sz = 0, root = roots[0];
        vector<bool> visited(n+1, false);
        // sum[i] : số nodes mà có height = i
        vector<int> sum(n+1, 0);
        function<int(int,int,int)> dfs = [&](int u, int par, int h){
            int sz_ = 1;
            visited[u] = true;
            for (auto v : g[u]) {
                int new_h = h + 1;
                sum[new_h]++;
                sz_ += dfs(v, u, new_h);
            }
            return sz_;
        };
        // sz : size of the binary tree rooted at root
        sz = dfs(root, 0, 0);
        bool isValid = true;
        for (int i = 1; i <= n; i++)
            if (visited[i] == false)
                isValid = false;

        if (isValid) {
            int total = 2 * C[n][2] + n*n;
            int s = 0;
            for (int i = 2; i <= n; i++)
                s += sum[i]*(i-1);
            cout << total - s << '\n';
        } else {
            function<vector<int>(int)> f = [&](int start) {
                // dfs from start to find cycle
                vector<int> cycle, s;
                bool found = false;
                vector<bool> visited2(n+1, false);
                function<void(int,int)> dfs2 = [&](int u, int prev){
                    visited[u] = true;
                    visited2[u] = true;
                    s.push_back(u);
                    for (auto v : g[u]) {
                        if (found) return;
                        if (visited[v] == false)
                            dfs2(v, u);
                        else if (v != 0 && visited2[v]) {
                            found = true;
                            for (int i = s.size()-1; i >= 0; i--) {
                                cycle.push_back(s[i]);
                                if (s[i] == v) break;
                            }
                        }
                    }
                    s.pop_back();
                };
                dfs2(start, 0);
                return cycle;
            };

            vector<vector<int>> cycles;
            for (int i = 1; i <= n; i++)
                if (visited[i] == false) {
                    vector<int> res = f(i);
                    if (!res.empty()) cycles.push_back(res);
                }

            if (cycles.size() >= 2) {
                cout << 0 << '\n';
            } else {
                assert(cycles.size() == 1);
                int len = cycles[0].size();
                cout << len*(sz-1) << '\n';
            }
        }
    }

    return 0;
}