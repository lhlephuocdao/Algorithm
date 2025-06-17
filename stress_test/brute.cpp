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
    // cin >> tc;
    while (tc--)
    {
        int n; cin >> n;
        vector<int> L(n+1), R(n+1);
        for (int i = 1; i <= n; i++) cin >> L[i];
        for (int i = 1; i <= n; i++) cin >> R[i];
        int ans = 0;
        
        function<void()> check = [&](){
            vector<vector<int>> g(n+1);
            vector<int> roots;
            vector<bool> checked(n+1, false);
            for (int i = 1; i <= n; i++) {
                g[i].push_back(L[i]);
                g[i].push_back(R[i]);
                checked[L[i]] = true;
                checked[R[i]] = true;
            }

            for (int i = 1; i <= n; i++)
                if (checked[i] == false) roots.push_back(i);

            if (roots.size() != 1) return;

            int root = roots[0];
            vector<bool> visited(n+1, false);
            function<void(int,int)> dfs = [&](int u, int par){
                visited[u] = true;
                for (auto v : g[u]) {
                    dfs(v, u);
                }
            };
            dfs(root, 0);

            bool isValid = true;
            for (int i = 1; i <= n; i++)
                if (visited[i] == false)
                    isValid = false;
            if (isValid) ans++;
        };

        // swap L[i], L[j]
        for (int i = 1; i < n; i++)
            for (int j = i+1; j <= n; j++) {
                swap(L[i], L[j]);
                check();
                swap(L[i], L[j]);
            }

        // swap (R[i], R[j])
        for (int i = 1; i < n; i++)
            for (int j = i+1; j <= n; j++) {
                swap(R[i], R[j]);
                check();
                swap(R[i], R[j]);
            }

        // swap L[i], R[j]
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                swap(L[i], R[j]);
                check();
                swap(L[i], R[j]);
            }

        cout << ans << '\n';
    }

    return 0;
}