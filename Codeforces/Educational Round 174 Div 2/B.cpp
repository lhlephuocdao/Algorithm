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
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
    
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x = a[i][j];
                bool check = true;
                
                if (i>0 && x == a[i-1][j]) check = false;
                if (i<n-1 && x == a[i+1][j]) check = false;
                if (j>0 && x == a[i][j-1]) check = false;
                if (j<m-1 && x == a[i][j+1]) check = false;

                if (!check || mp[x] == 0)
                    mp[x]++;

            }
        }
        int ans = 0;
        vector<int> v;
        for (auto x : mp)
            v.push_back(std::min(x.second, 2ll));

        sort(v.begin(), v.end());

        // for (auto x : mp)
        //     cout << x.first << ' ' << x.second << '\n';

        for (int i = 0; i < v.size() - 1; i++)
            ans += v[i];

        cout << ans << '\n';
    }
    return 0;
}