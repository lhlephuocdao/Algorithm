#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<vector<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<int>& a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n+1, vector<int>(n+1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];

        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }

        vector<int> suffix(n+1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= 1; j--) {
                if (a[i][j] == 1)
                    suffix[i]++;
                else
                    break;
            }
        }


        for (int i = 1; i <= n; i++)
            if (suffix[i] == 0) suffix[i] = 400;

        sort(suffix.begin(), suffix.end());
        // debug(suffix);
        int ans = 0;
        int current = 1;
        for (int i = 1; i <= n; i++)
        {
            if (suffix[i] == 400) {
                break;
            } else if (suffix[i] >= current) {
                ans = current;
                current++;
            }
        }
        cout << min(ans+1, n) << '\n';
    }
    return 0;
}