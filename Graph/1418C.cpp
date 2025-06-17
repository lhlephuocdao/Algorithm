#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<vector<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<set<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<int>& a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

void debug(map<int, vector<int>>& m)
{
    for (auto v : m) {
        cout << v.first << " : ";
        for (auto x : v.second)
            cout << x << ' ';
        cout << '\n';
    }
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        if (n == 1) {
            cout << a[0] << '\n';
            continue;
        }

        vector<vector<int>> dp(n, vector<int>(2, INT_MAX));
        dp[0][0] = a[0];
        dp[0][1] = a[0];

        dp[1][0] = a[0] + a[1];
        dp[1][1] = dp[0][0];

        for (int i = 2; i < n; i++)
        {
            dp[i][0] = min(dp[i-1][1] + a[i], dp[i-2][1] + a[i-1] + a[i]);
            dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
        }

        cout << min(dp[n-1][0], dp[n-1][1]) << '\n';
    }
    return 0;
}