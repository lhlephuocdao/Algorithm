#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

int32_t main()
{
    // fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,x,k;
        cin >> n >> x >> k;

        string s;
        cin >> s;
        s = ' ' + s;
        vector<int> v(n+1, 0);
        int first = 0;
        int first_zero = 0;
        for (int i = 1; i <= n; i++)
        {
            int a = (s[i] == 'L') ? -1 : 1;
            v[i] = v[i-1] + a;

            if (v[i] + x == 0 && first == 0) {
                first = i;
            }

            if (v[i] == 0 && first_zero == 0) {
                first_zero = i;
            }
        }

        // for (int i = 1; i <= n; i++)
        //     cout << v[i] << ' ';
        // cout << '\n';

        // cout << first << " " << first_zero << '\n';

        int ans = 0;
        if (first != 0) {
            ans = 1;
            k -= first;

            if (k > 0 && first_zero != 0) {
                ans += k/first_zero;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}