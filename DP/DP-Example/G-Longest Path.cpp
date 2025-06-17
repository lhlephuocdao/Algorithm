#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;
int n, m;
vector<vector<int>> adj;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
    }

    vector<int> dp(n, -1);

    function<int(int)> fn = [&](int u){
        if (dp[u] != -1)
            return dp[u];
        
        dp[u] = 0;
        for (auto v : adj[u]) {
            dp[u] = max(dp[u], fn(v) + 1);
        }

        return dp[u];
    };

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        ans = max(ans, fn(i));

    cout << ans << '\n';

    return 0;
}