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
        vector<int> a(n), b(n);
        int x = 0, suma = 0, sumb = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            suma += a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sumb += b[i];
        }

        vector<int> d(n);
        int count = 0;
        int idx = -1;
        bool is_zero = false;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[i]) {
                count++;
                if (idx == -1)
                    idx = i;
            } else if (a[i] == 0) is_zero = true;

            d[i] = a[i] - b[i];
        }

        int dif = suma - sumb;
            bool ans = true;
        if (n == 2)
            if (suma >= sumb)
                ans = true;
            else
                ans = false;
        else {
            if (count >= 2)
                ans = false;
            else if (count == 0)
                ans = true;
            else {
                for (int i = 0; i < n; i++)
                {
                    if (i != idx) {
                        if (d[i] + d[idx] < 0)
                        {
                            ans = false;
                            break;
                        }
                    }
                }

            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}