#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        if (n == 1) {
            cout << -1 << '\n';
        } else {
            bool found = false;
            int idx = -1, len = 0;
            for (int i = 0; i < n-1; i++) {
                if (s[i] == s[i+1]) {
                    idx = i;
                    len = 2;
                    break;
                }

                if (i+2 < n) {
                    if (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) {
                        idx = i;
                        len = 3;
                        break;
                    }
                }
            }

            if (idx == -1)
                cout << -1 << '\n';
            else {
                for (int i = idx; i < idx+len; i++)
                    cout << s[i];
                cout << '\n';
            }
        }
    }

    return 0;
}