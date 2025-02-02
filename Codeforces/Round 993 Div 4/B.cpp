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
        string a;
        cin >> a;
        int n = a.length();
        for (int i = n-1; i >= 0; i--)
        {
            if (a[i] == 'p') cout << 'q';
            else if (a[i] == 'q') cout << 'p';
            else cout << a[i];
        }
        cout << '\n';
    }

    return 0;
}