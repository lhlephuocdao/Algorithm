#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    const int maxm = 1e5 + 7;
    vector<vector<int>> factors(maxm);
    for (int i = 1; i <= maxm; i++)
        for (int j = i; j <= maxm; j+=i)
            factors[j].push_back(i);

    int t; cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());

        int ans = LONG_LONG_MAX;
        int count = 0, j = 0;
        vector<int> fre(m+1, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto x : factors[a[i]])
            {
                if (x > m) break;
                if (fre[x] == 0) count++;
                fre[x]++;
            }

            while (count == m)
            {
                int diff = a[i] - a[j];
                ans = min(ans, diff);

                for (auto x : factors[a[j]])
                {
                    if (x > m) break;
                    fre[x]--;
                    if (fre[x] == 0) count--;
                }
                j++;
            }
        }

        if (ans != LONG_LONG_MAX)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}