#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        int l = 0, r = 0;
        int ans = 0;
        for (int i = 0; i < n-1; i++)
        {
            int x = 0, y = 0;
            for (int j = i+1; j < n; j++)
            {
                if (a[j] < a[i]) x++;
                else if (a[j] > a[i]) y++;

                if (x-y > ans) {
                    ans = x-y;
                    l = i;
                    r = j;
                }
            }
        }

        cout << l+1 << " " << r+1 << '\n';
    }
    return 0;
}