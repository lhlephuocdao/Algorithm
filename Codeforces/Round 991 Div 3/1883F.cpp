#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n; cin >> n;
    vector<int> a(n), right(n+1, 0), left(n, 0);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (m[a[i]] == 0) {
            left[i] = 1;
            m[a[i]]++;
        }
    }

    m.clear();
    for (int i = n-1; i >= 0; i--)
    {
        if (m[a[i]] == 0) {
            m[a[i]]++;
            right[i] = right[i+1] + 1;
        } else {
            right[i] = right[i+1];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (left[i] == 1) {
            ans += right[i];
        }
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}