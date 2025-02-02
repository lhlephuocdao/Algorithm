#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            int a; cin >> a;
            if (i != n-2) ans += a;
            else ans -= a;
        }
        cout << ans << '\n';
    }

    return 0;
}