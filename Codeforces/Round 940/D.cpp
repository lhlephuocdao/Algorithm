#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

void debug(vector<int>& a)
{
    for (auto& x : a) cout << x << ' ';
    cout << '\n';
}

int count_bit(int x)
{
    int i = 0;
    while (x)
    {
        x /= 2;
        i++;
    }

    return i-1;
}

int32_t main()
{
    fastio;

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n+1, 0), prefix(n+1, 0), bit(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            prefix[i] = prefix[i-1]^a[i];
            bit[i] = count_bit(a[i]);
        }
        // debug(prefix);
        // debug(bit);
        int dp[n+1][40][2];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < 40; i++) dp[0][i][0] = 1;

        for (int k = 1; k <= n; k++)
        {
            for (int i = 0; i < 40; i++)
            {
                dp[k][i][1] = dp[k-1][i][1] + ((prefix[k]&(1<<i)) != 0 ? 1 : 0);
                dp[k][i][0] = dp[k-1][i][0] + ((prefix[k]&(1<<i)) == 0 ? 1 : 0);
            }
        }

        int ans = 0;
        for (int y = 1; y <= n; y++)
        {
            int x = y, z = n;
            int i = bit[y];

            ans += dp[x-1][i][1]*(dp[z][i][1] - dp[y-1][i][1]);
            ans += dp[x-1][i][0]*(dp[z][i][0] - dp[y-1][i][0]);
        }

        cout << ans << '\n';
    }

    return 0;
}