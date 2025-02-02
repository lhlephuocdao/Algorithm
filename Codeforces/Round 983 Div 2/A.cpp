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
        int n; cin >> n;
        int n0 = 0;
        for (int i = 0; i < 2*n; i++) {
            int a; cin >> a;
            if (a == 0) n0++;
        }
        int n1 = 2*n - n0;
        int mi = n - (n0/2 + n1/2);
        int ma = min(n0, n1);
        cout << mi << " " << ma << '\n';
    }

    return 0;
}