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
        int m,a,b,c;
        cin >> m >> a >> b >> c;
        int ans = min(m, a) + min(m, b);
        int du = 0;
        if (m > a) du += m-a;
        if (m > b) du += m-b;
        ans += min(du, c);
        cout << ans << '\n';
    }

    return 0;
}