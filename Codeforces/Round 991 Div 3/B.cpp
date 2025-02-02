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
        int sum = 0;
        int sum_chan = 0, sum_le = 0;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if (i%2 == 0)
                sum_chan += a[i];
            else
                sum_le += a[i];
        }

        if (sum%n != 0) {
            cout << "NO\n";
        } else {
            int d = sum/n;
            if (n%2 == 0) {
                int n_chan = n/2, n_le = n/2;
                if (n_chan * d == sum_chan && n_le*d == sum_le)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            } else {
                int n_le = (n+1)/2, n_chan = n/2;
                if (n_chan * d == sum_chan && n_le*d == sum_le)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }

    return 0;
}