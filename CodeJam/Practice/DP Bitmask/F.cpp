#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
int n, maxw;
int w[maxn];
pair<int, int> dp[1<<maxn];

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0); cout.tie(0);

    cin >> n >> maxw;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < (1<<n); i++) {
        dp[i].first = INT_MAX;
        dp[i].second = 0;
    }
    dp[0].first = 1;
    dp[0].second = maxw;

    for (int i = 0; i < (1<<n); i++) // i : subset of people is already in the elevator
    {
        for (int x = 0; x < n; x++)
        {
            if (i & (1<<x)) continue; 

            int m = dp[i].second;
            if (w[x] <= m) {
                dp[i | (1<<x)].first = min(dp[i | (1<<x)].first, dp[i].first);
                dp[i | (1<<x)].second = max(dp[i | (1<<x)].second, m-w[x]);
            } else {
                dp[i | (1<<x)].first = min(dp[i | (1<<x)].first, dp[i].first + 1);
                dp[i | (1<<x)].second = max(dp[i | (1<<x)].second, max(m, maxw-w[x]));
            }
        }
    }

    cout << dp[(1<<n) - 1].first << '\n';

    return 0;
}