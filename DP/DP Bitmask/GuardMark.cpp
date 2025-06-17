#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX_N = 20;
const int MAX = 1e9;

int N, H;
ll dp[1<<MAX_N];
ll he[1<<MAX_N];
ll s[MAX_N], w[MAX_N], h[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    #if 0
    freopen("guard.in","r",stdin);
    freopen("guard.out","w",stdout);
    #endif

    cin >> N >> H;
    for (int i = 0; i < N; i++)
        cin >> h[i] >> w[i] >> s[i];

    memset(he, 0, sizeof(he));
    memset(dp, -1, sizeof(dp));

    ll ans = -1;

    for (int x = 0; x < N; x++) {
        dp[1<<x] = s[x];
        he[1<<x] = h[x];
    }

    for (int i = 0; i < (1<<N); i++)    // i : subset of cows that are stacked
    {
        if (he[i] >= H || dp[i] <= 0) { // reach enough height or reach maximum weight
            ans = std::max(ans, dp[i]);
            continue;
        }

        for (int x = 0; x < N; x++)
        {
            // cow x-th is not stacked yet mimimum strength is larger than weight of cow x-th
            if (!(i & (1<<x)) && dp[i] >= w[x]) {
                dp[i | (1<<x)] = std::max(dp[i | (1<<x)], std::min(dp[i] - w[x], s[x]));
                he[i | (1<<x)] = he[i] + h[x];
            }
        }
    }

    if (ans >= 0)
        cout << ans << '\n';
    else
        cout << "Mark is too tall\n";

    return 0;
}