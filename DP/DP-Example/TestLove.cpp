#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string a; cin >> a;
    a = 'd' + a;

    vector<int> dp(n+2, -1);
    dp[0] = k;

    for (int i = 1; i <= n+1; i++)
    {
        for (int x = 1; x <= m; x++)
        {
            if (((i-x)>=1 && a[i-x]=='L') || i-x == 0) dp[i] = max(dp[i], dp[i-x]);
        }

        if (a[i-1] == 'W') dp[i] = max(dp[i], dp[i-1]-1);
    }

    if (dp[n+1] >= 0) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}