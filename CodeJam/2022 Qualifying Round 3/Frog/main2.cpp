#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, a, b;
    cin >> a >> b >> x;
    int gcd = __gcd(a, b);
    cout << x/gcd << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}