#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        bool check = true;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            int diff = abs(a[i] - a[j]);
            if (diff % k == 0) {
                check = false;
                break;
            }
        }
        if (check) {
            cout << "YES\n";
            cout << i+1 << '\n';
            return;
        }
    }
    cout << "NO\n";
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