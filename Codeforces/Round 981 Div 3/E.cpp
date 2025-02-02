#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> adj(n+1);
        for (int i = 1; i <= n; i++)
        {
            int v; cin >> v;
            adj[i] = v;
        }

        vector<int> visited(n+1, 0);
        vector<int> stack;
        int ans = 0;

        function<void(int)> dfs = [&](int node){
            visited[node] = 1;
            stack.push_back(node);

            int next_node = adj[node];
            if (visited[next_node] == 0)
                dfs(next_node);
            else if (visited[next_node] == 1) {
                int sz = 0;
                for (int i = stack.size() - 1; i >= 0; i--) {
                    sz++;
                    if (stack[i] == next_node) break;
                }
                ans += (sz-1)/2;
            }

            visited[node] = 2;
            stack.pop_back();
        };

        for (int i = 1; i <= n; i++)
            if (visited[i] == 0)
                dfs(i);

        cout << ans << '\n';
    }

    return 0;
}