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
        string s;
        cin >> s;
        int n = s.length();
        bool check = false;
        for (int i = 0; i < n-1; i++)
        {
            if (s[i] == s[i+1]) {
                check = true;
                break;
            }
        }
        if (check)
            cout << 1 << '\n';
        else
            cout << n << '\n';
    }
    return 0;
}