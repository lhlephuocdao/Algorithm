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

void debug(vector<pair<int, int>>& a)
{
    for (auto x : a)
        cout << x.first << ' ' << x.second << '\n';
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if (abs(n-m) > k || max(n,m) < k) {
            cout << -1 << '\n';
            continue;
        }

        char s1 = '0', s2 = '1';
        if (n < m) {
            swap(s1, s2);
            swap(n, m);
        }

        string ans;
        for (int i = 0; i < k; i++)
            ans += s1;

        for (int i = 0; i < max(m, n-k); i++)
        {
            if (i < m) ans += s2;
            if (i < n-k) ans += s1;
        }

        cout << ans << '\n';
    }
    return 0;
}