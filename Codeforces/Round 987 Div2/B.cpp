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
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        int i = 0;
        bool check = true;
        while( i < n-1)
        {
            if (p[i] == i) {
                i++;
                continue;
            }

            if (p[i] != i+1 || p[i+1] != i) {
                check = false;
                break;
            } else {
                i += 2;
            }
        }
        if (check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}