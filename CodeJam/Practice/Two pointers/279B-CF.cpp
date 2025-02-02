#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    int l = 0, r = 0;
    int sum = 0, time = t;
    while (r < n)
    {
        while (r < n && time >= a[r]) {
            sum++;
            time -= a[r];
            r++;
            ans = max(ans, sum);
        }

        while (l <= r && time < a[r]) {
            time += a[l];
            l++;
            sum--;
        }
    }

    cout  << ans << '\n';

    return 0;
}