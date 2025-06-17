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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        sort(b.begin(), b.end());

        bool ans = true;

        if (b[0] - a[0] < a[0])
            a[0] = b[0] - a[0];

        for (int i = 1; i < n; i++)
        {
            int tmp = a[i-1] + a[i];
            auto itr = lower_bound(b.begin(), b.end(), tmp);
            if (itr != b.end()) {
                int new_a = *itr - a[i];
                if (a[i] < a[i-1])
                    a[i] = new_a;
                else {
                    a[i] = min(a[i], new_a);
                }
            }
        }

        for (int i = 0; i < n-1; i++)
            if (a[i] > a[i+1]) {
                ans = false;
                break;
            }
        

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}