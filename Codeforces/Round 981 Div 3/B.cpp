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
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        int ans = 0;
        for (int startCol = 0; startCol < n; startCol++) {
            int i = 0;
            int j = startCol;
            int _max = 0;
            while (i < n && j < n) {
                if (a[i][j] < 0) _max = max(_max, -a[i][j]);
                i++;
                j++;
            }
            ans += _max;
        }

        for (int startRow = 1; startRow < n; startRow++) {
            int i = startRow;
            int j = 0;
            int _max = 0;
            while (i < n && j < n) {
                if (a[i][j] < 0) _max = max(_max, -a[i][j]);
                i++;
                j++;
            }
            ans += _max;
        }
        cout << ans << '\n';
    }

    return 0;
}