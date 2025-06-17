#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define pii pair<int, int>
#define int long long

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> r(n+1, n); 
        // r[i] : điểm xa nhất bên tay phải mà ta có thể start từ điểm i 
        for (int i = 0; i < m; i++)
        {
            int s,e;
            cin >> s >> e;
            if (s > e) swap(s, e);

            r[s] = min(r[s], e-1);
            // cout << "r[" << s << "]: " << r[s] << '\n';
        }

        for (int i = n-1; i >= 0; i--) {
            r[i] = min(r[i], r[i+1]);
            // cout << "r[" << i << "]: " << r[i] << '\n';
        }
        
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            ans += r[i] - i;
        }

        cout << ans + n << '\n';
    }
    return 0;
}