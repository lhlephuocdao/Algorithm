#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<int>& a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

int32_t main()
{
    fastio;

    int t = 1ll;
    cin >> t;
    for (int idx = 1ll; idx <= t; idx++)
    {
        int m, n;
        cin >> m >> n;
        vector<int> s(m);
        for (int i = 0; i < m; i++)
            cin >> s[i];

        int dp[11][11];
        memset(dp, -1, sizeof(dp));

        function<int(int,int, bool)> call = [&](int pos, int prev, bool first){
            if (pos == n) return 1ll;
            if (dp[pos][prev] != -1) return dp[pos][prev];

            int res = 0;
            int start, end, pre_val;
            if (first) {
                start = 0;
                end = m-1;
            } else {
                pre_val = s[prev];
                start = max(0ll, prev-2);
                end = min(prev+2, m-1);
            }
            
            // cout << "pos: " << pos << '\n';
            for (int i = start; i <= end; i++)
            {
                int val = s[i];
                if (first) pre_val = val;
                // cout << "val: " << val << '\n';
                if (abs(pre_val - val) <= 2ll)
                {
                    res += call(pos+1, i, false);
                }
            }
            // cout << "dp " << pos << " " << prev << " : " << res << '\n';
            return dp[pos][prev] = res;
        };

        cout << "Case " << idx << ": " << call(0, 0, true) << '\n';
    }

    return 0;
}