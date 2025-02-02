#include <bits/stdc++.h>
using namespace std;
#define int long long



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    const int maxn = 1e5 + 1;
    vector<int> g(maxn, 1);
    for (int i = 2; i <= maxn; i++)
    {
        for (int j = 2*i; j <= maxn; j += i)
            g[j] = i;
    }

    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> x(m+1);
        for (int i = 1; i <= m; i++) cin >> x[i];
        sort(x.begin()+1, x.end(), greater<int>());

        vector<int> ans(n+1), index(n+1);
        bool check = true;
        index[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int ma = g[i];
            if (index[ma] + 1 <= m) index[i] = index[ma] + 1;
            else {
                check = false;
                break;
            }
        }

        if (check) {
            for (int i = 1; i <= n; i++) cout << x[index[i]] << " ";
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}