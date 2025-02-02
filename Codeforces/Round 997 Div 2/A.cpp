#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0, w = 0, h = 0;
        bool first = true;
        while (n--)
        {
            int x, y;
            cin >> x >> y;
            if (first)
            {
                first = false;
                continue;
            }

            w += x;
            h += y;
        }

        cout << (w+h+2*m)*2 << '\n';
    }
    return 0;
}