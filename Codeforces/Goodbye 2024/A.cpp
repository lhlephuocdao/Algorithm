#include <bits/stdc++.h>
using namespace std;
#define int long long

void log(vector<int>& a) {
    for (auto x : a) cout << x << ' ';
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool check = false;
        for (int i = 0; i < n-1; i++) {
            int x = min(a[i], a[i+1]);
            int y = max(a[i], a[i+1]);
            if (2*x > y) {
                check = true;
                break;
            }
        }
        if (check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}