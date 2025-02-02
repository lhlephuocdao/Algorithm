#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int a,b;
        cin >> a >> b;
        if (a >= b)
            cout << a << '\n';
        else {
            int t = 2*a - b;
            if (t > 0) cout << t << '\n';
            else cout << 0 << '\n';
        }
    }

    return 0;
}