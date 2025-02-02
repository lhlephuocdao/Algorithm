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
            for (int i = 1; i <= n/2; i++)
                cout << i << " " << i << " ";
        } else {
            if (n < 27) cout << -1 << '\n';
            else {
                int v = 3, count = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (i == 1 || i == 10 || i == 26) {
                        cout << 1 << " ";
                    } else if (i == 23 || i == 27) {
                        cout << 2 << " ";
                    } else {
                        cout << v << " ";
                        count++;
                        if (count == 2) {
                            count = 0;
                            v++;
                        }
                    }
                }
            }
        }
    }

    return 0;
}