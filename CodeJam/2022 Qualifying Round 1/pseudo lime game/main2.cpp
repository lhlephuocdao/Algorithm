#include <bits/stdc++.h>

using namespace std;

int n, L, F;

void solve()
{
    cin >> n >> L >> F;
    map<string, int> m;

    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        string sub = s.substr(L-F, F);
        m[sub]++;
    }

    int ans = 0;
    for (auto itr = m.begin(); itr != m.end(); itr++)
        ans += itr->second/2;
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}