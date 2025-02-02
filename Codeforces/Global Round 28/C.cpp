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
        string s; cin >> s;
        string expected;
        int n = s.length();

        int i = 0;
        while (s[i] == '1') i++;

        int p = i;

        for (; i < n; i++)
            if (s[i] == '0') expected += '1';
            else expected += '0';

        int ex_n = expected.length();

        if (ex_n == 0) {
            cout << 1 << " " << 1 << " " << 1 << " " << n << '\n';
        } else {
            int l = 1, r = n - ex_n;
            int ex_one = 0;
            for (int id = 0; id < ex_n; id++)
                if (expected[id] == '1') ex_one++;
                else break;

            int l1, r1;
            if (ex_one > r) {
                l1 = 1;
                r1 = ex_n;
            } else {
                l1 = r-ex_one+1;
                r1 = l1 + ex_n - 1;
            }

            cout << l1 << " " << r1 << " " << 1 << " " << n << '\n';
        }
    }

    return 0;
}