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
        string s;
        cin >> s;
        int cnt = 0;
        int idx = 0;
        char c = s[0];
        bool s_turn = true;
        while (idx < n)
        {
            if (s_turn) {
                while (idx < n && s[idx] == '0') idx++;
                if (idx < n) {
                    cnt++;
                    s_turn = false;
                }
            } else {
                while (idx < n && s[idx] == '1') idx++;
                if (idx < n) {
                    cnt++;
                    s_turn = true;
                }
            }

        }
        cout << cnt << '\n';
    }
    return 0;
}