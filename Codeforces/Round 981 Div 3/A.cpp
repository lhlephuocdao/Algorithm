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
        if (n%2 == 0) {
            cout << "Sakurako\n";
        } else {
            cout << "Kosuke\n";
        }
    }

    return 0;
}