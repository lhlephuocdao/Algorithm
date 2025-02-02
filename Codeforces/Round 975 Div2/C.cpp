#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int ans, int sum, int maxa, int k)
{
    int target = maxa*ans;
    int lo = max(target, sum);
    int hi = sum + k;

    int t = hi/ans;
    int p = t*ans;
    return p >= lo;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int sum = 0, maxa = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            maxa = max(maxa, a[i]);
        }

        int ans;
        for (int i = n; i >= i; i--)
            if (check(i, sum, maxa, k)) {
                ans = i;
                break;
            }

        cout << ans << '\n';
    }

    return 0;
}