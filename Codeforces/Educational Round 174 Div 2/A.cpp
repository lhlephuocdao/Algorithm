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
        vector<int> b(n-2);
        for (auto& x : b) cin >> x;
        // vector<int> a(n, -1);
        // int cnt = 1;
        // for (int i = 0; i < n-2; i++)
        // {
        //     int j = i+1;

        // }
        bool check = true;
        for (int i = 0; i < n-4; i++)
        {
            if (b[i] == 1 && b[i+1] == 0 && b[i+2] == 1)
                check = false;
        }
        if (check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}