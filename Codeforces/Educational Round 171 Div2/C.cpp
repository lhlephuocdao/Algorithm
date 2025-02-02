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
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++)
            a[i] = s[i-1] - '0';

        int ans = 0, cnt = 0;
        for (int i = n; i >= 1; i--)
        {
            if (a[i] == 1) {
                if (i-1 >= cnt+1)
                    cnt++;
                else {
                    ans += i;
                    if (cnt > 0) cnt--;
                }
            } else {
                ans += i;
                if (cnt > 0) cnt--;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}