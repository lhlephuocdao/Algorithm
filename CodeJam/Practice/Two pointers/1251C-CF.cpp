#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a;
    cin >> a;
    vector<char> chan, le;

    for (int i = 0; i < a.length(); i++)
        if (a[i]%2 == 0) chan.push_back(a[i]);
        else le.push_back(a[i]);

    int n = chan.size(), m = le.size();
    int i = 0, j = 0;
    string ans = "";
    while (i < n || j < m)
    {
        if (j == m || (i<n && chan[i]<le[j]))
            ans += chan[i++];
        else
            ans += le[j++];
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}