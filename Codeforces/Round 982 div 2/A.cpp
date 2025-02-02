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
        int mw = 0, mh = 0;
        for (int i = 0; i < n; i++)
        {
            int w, h;
            cin >> w >> h;
            mw = max(mw, w);
            mh = max(mh, h);
        }
        cout << (mw+mh)*2 << '\n';
    }

    return 0;
}