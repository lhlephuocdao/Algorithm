#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;
int n;
vector<vector<int>> adj;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++)
    {
        int x,y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // 0 : white
    // 1 : black
    vector<vector<ll>> dp(2, vector<ll>(n, -1));
    function<int(int, int, int)> fn = [&](int pre, int u, int color){
        if (dp[color][u] != -1) {
            return dp[color][u];
        }
        dp[color][u] = 1;
        for (auto v : adj[u]) {
            if (v == pre) continue;

            if (color == 0) {
                int w = fn(u, v, color);
                int b = fn(u, v, color+1);
                dp[color][u] = (dp[color][u] * ((w + b)%mod))%mod;
            } else {
                dp[color][u] = (dp[color][u] * fn(u, v, (color+1)%2))%mod;
            }
        }

        return dp[color][u];
    };

    cout << (fn(-1, 0, 0) + fn(-1, 0, 1))%mod << '\n';

    return 0;
}