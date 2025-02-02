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
        int n, k;
        cin >> n >> k;
        vector<int> ans(n, 0);
        int idx = 1;
        int p = k;
        while (p <= n) {
            ans[p-1] = idx;
            idx++;
            p += k;
        }

        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {
                ans[i] = idx;
                idx++;
            }
        }

        for (auto x : ans) cout << x << " ";
        cout << '\n';
    }

    return 0;
}