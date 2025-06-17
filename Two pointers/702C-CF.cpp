#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int l = 0, r = 2e9;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l+r)/2;
        int j = 0;
        bool check = false;
        for (int i = 0; i < m; i++)
        {
            int left = b[i]-mid;
            int right = b[i]+mid;
            while (j < n && a[j] >= left && a[j] <= right)
                j++;
            if (j == n) {
                check = true;
                break;
            }
        }
        if (check) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout << ans << '\n';

    return 0;
}