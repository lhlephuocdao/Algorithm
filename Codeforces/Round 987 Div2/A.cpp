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
        vector<int> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];
        int count = 0, ma = 1, i = 0;
        while (i < n-1) {
            while (i < n-1 && h[i] == h[i+1]) {
                count++;
                i++;
            }
            ma = max(ma, count+1);
            count = 0;
            i++;
        }

        cout << n - ma << '\n';
    }

    return 0;
}