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
        int x; cin >> x;
        if (x < 33 || (x%33 != 0))
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}