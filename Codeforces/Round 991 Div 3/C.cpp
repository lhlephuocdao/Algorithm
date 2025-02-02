#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;
        cin >> s;
        int n = s.length();
        int sum = 0;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            sum += s[i] - '0';
            if (s[i] == '2')
                m[2]++;
            else if (s[i] == '3')
                m[6]++;
        }

        if (sum%9 == 0)
            cout << "YES\n";
        else {
            int dif = sum%9;
            // cout << "dif: " << dif << '\n';
            int n2 = m[2], n6 = m[6];

            if (n2>0 && n6>0) {
                for (int i = 0; i <= n2; i++)
                    for (int j = 0; j <= n6; j++)
                    {
                        int total = 2*i + 6*j;
                        // cout << "total: " << total << "\n";
                        if ((total+dif)%9 == 0) {
                            cout << "YES\n";
                            return;
                        }
                    }

                cout << "NO\n";
            } else if (n2>0) {
                for (int i = 0; i <= n2; i++)
                {
                    int total = 2*i;
                    // cout << "total: " << total << "\n";
                    if ((total+dif)%9 == 0) {
                        cout << "YES\n";
                        return;
                    }
                }
                cout << "NO\n";
            } else if (n6 > 0) {
                for (int i = 0; i <= n6; i++)
                {
                    int total = 6*i;
                    // cout << "total: " << total << "\n";
                    if ((total+dif)%9 == 0) {
                        cout << "YES\n";
                        return;
                    }
                }
                cout << "NO\n";
            } else {
                cout << "NO\n";
            }

        }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}