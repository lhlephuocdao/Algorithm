#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

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
        int x = sqrt(n);
        if (x*x != n) {
            cout << "No\n";
            continue;
        }

        if (n == 2) {
            if (s == "1111")
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }

        bool check = true;
        s = ' ' + s;
        for (int i = 1; i <= x; i++)
            if (s[i] != '1') {
                check = false;
                break;
            }

        for (int i = n; i > n-x; i--)
            if (s[i] != '1') {
                check = false;
                break;
            }

        for (int i = 2; i <= x-1; i++)
        {
            for (int j = 1; j <= x; j++)
            {
                int idx = (i-1)*x + j;
                if (j==1 || j==x) {
                    if (s[idx] == '0') {
                        check = false;
                        break;
                    }
                } else {
                    if (s[idx] == '1') {
                        check = false;
                        break;
                    }
                }
            }

            if (!check) break;
        }

        if (check)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}