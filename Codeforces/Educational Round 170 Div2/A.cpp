#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    while (q--)
    {
        string s, t;
        cin >> s >> t;
        int i = 0;
        while (i < min(s.length(), t.length()) && s[i] == t[i]) i++;

        int ans = (i > 0) ? i+1 : 0;
        if (i < s.length()) ans += s.length() - i;
        if (i < t.length()) ans += t.length() - i;
        cout << ans << '\n';
    }

    return 0;
}