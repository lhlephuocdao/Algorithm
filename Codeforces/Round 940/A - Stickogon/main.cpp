#include <bits/stdc++.h>

using namespace std;

int n;

void solve()
{
    cin >> n;
    unordered_map<int, int> m;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        m[x]++;
    }
    int ans = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        ans += it->second/3;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}