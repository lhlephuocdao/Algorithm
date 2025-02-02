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
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        function<int(int, int)> f = [](int x, int a){
            if (x < a) x++;
            else if (x>a) x--;
            return x;
        };

        vector<vector<int>> dp(3, vector<int>(n+1, 0));
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = f(dp[0][i-1], a[i]);
            dp[1][i] = max(dp[0][i-1], dp[1][i-1]);
            if (i>1) dp[2][i] = max(f(dp[1][i-1], a[i]), f(dp[2][i-1], a[i]));
        }

        cout << max(dp[1][n], dp[2][n]) << '\n';
    }

    return 0;
}