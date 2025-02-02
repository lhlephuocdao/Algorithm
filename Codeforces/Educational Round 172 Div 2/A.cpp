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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end(), greater<int>());
        for (int i = 1; i < n; i++)
            a[i] = a[i] + a[i-1];
        int min_diff = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] <= k) {
                min_diff = min(min_diff, k-a[i]);
            }
        }

        if (sum < k) {
            ans = max(min_diff, k-sum);
        } else {
            ans = min_diff;
        }

        cout << ans << '\n';
    }

    return 0;
}