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

void debug(vector<set<int>>& a)
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

void debug(map<int, vector<int>>& m)
{
    for (auto v : m) {
        cout << v.first << " : ";
        for (auto x : v.second)
            cout << x << ' ';
        cout << '\n';
    }
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        
        int ans = 9;
        for (int i = 0; i <= 8; i++)
        {
            string s = to_string(n-i);
            int x = 7; // = (7 - 0)%10
            for (auto a : s)
            {
                // cout << "a : " << a << '\n';
                x = min(x, ((int)('7' - a) + 10)%10);
                // cout << "x : " << x << '\n';
            }
            if (x <= i) ans= min(ans, i);
        }

        cout << ans << '\n';
    }
    return 0;
}