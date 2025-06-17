#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

int32_t main()
{
    fastio;

    // freopen("candy.inp", "r", stdin);
    // freopen("candy.out", "w", stdout); 

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        int total = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
        }

        int half = total/2;
        bitset<600000 + 10> dp;
        dp[0] = true;
        for (int i = 0; i < n; i++)
            dp = dp | dp << a[i];

        int s1 = 0;
        for (int i = half; i >= 0; i--)
            if (dp[i]) {
                s1 = i;
                break;
            }

        cout << (total - 2*s1) << '\n';
    }
    return 0;
}