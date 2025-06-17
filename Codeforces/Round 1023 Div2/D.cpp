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
        int n; cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n-1; i++) {
            int u,v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<tuple<int,int,int>> ans;
        vector<bool> avai(n, true);

        function<void(int)> f = [&](int start) {
            vector<int> dis(n, -1);
            dis[start] = 0;

            int max_d = 0;
            int B = start, C = -1;
            vector<int> par(n, -1);

            function<void(int,int,int&, bool)> dfs = [&](int u, int prev, int& node, bool find_par){
                for (auto v : adj[u]) {
                    if (v == prev || avai[v] == false) continue;
                    dis[v] = dis[u] + 1;
                    if (dis[v] > max_d) {
                        max_d = dis[v];
                        node = v;
                    } else if (dis[v] == max_d) {
                        node = max(node, v);
                    }
                    if (find_par) par[v] = u;
                    dfs(v, u, node, find_par);
                }
            };

            dfs(start, -1, B, false);
            dis.assign(n, -1);
            dis[B] = 0;
            max_d = 0;
            C = B;
            dfs(B, -1, C, true);
            for (int v = C; v != -1; v = par[v])
                avai[v] = false;

            // cout << max_d << " " << B+1 << " " << C+1 << '\n';
            if (B<C) swap(B,C);
            ans.push_back({max_d+1, B+1, C+1});
        };

        // f(0);
        // for (auto x : avai) cout << x << ' ';
        // cout << '\n';

        // int i = 0;
        // while (i < n) {
        //     if (avai[i]) f(i);
        //     else i++;
        // }

        while (true) {
            if (count(avai.begin(), avai.end(), true) == 0)
                break;
            for (int i = 0; i < n; i++)
                if (avai[i])
                    f(i);
        }

        sort(ans.begin(), ans.end(), [&](tuple<int,int,int>& a, tuple<int,int,int>& b){
            int da = get<0>(a);
            int db = get<0>(b);
            if (da != db) return da > db;
            else return get<1>(a) > get<1>(b);
        });

        for (auto x : ans) cout << get<0>(x) << ' ' << get<1>(x) << ' ' << get<2>(x) << ' ';
        cout << '\n';
    }
    return 0;
}