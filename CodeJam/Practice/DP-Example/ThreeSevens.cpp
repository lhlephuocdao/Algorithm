#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int m;
    cin >> m;
    vector<vector<int>> a(m);
    for (int i = 0; i < m; i++)
    {
        int n; cin >> n;
        a[i].resize(n);
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    vector<vector<int>> ans(m);
    set<int> s;
    bool exist = true;
    for (int i = m-1; i >= 0; i--)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (s.find(a[i][j]) == s.end()) {
                ans[i].push_back(a[i][j]);
                s.insert(a[i][j]);
                // cout << "insert " << a[i][j] << " into set and a[" << i << "]\n";
            }
        }

        if (ans[i].empty()) {
            exist = false;
            break;
        }
    }

    // for (int i = 0; i < m; i++) {
    //     for (auto x : ans[i])
    //         cout  << x << " ";
    //     cout << '\n';
    // }

    if (!exist) cout << -1 << '\n';
    else {
        for (int i = 0; i < m; i++) cout << ans[i][0] << " ";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}