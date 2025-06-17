#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

int32_t main()
{
    fastio;

    const int maxn = 500;
    vector<vector<int>> C(maxn + 10, vector<int>(maxn + 10));

    for (int i = 0; i <= maxn; i++){
        C[i][0] = 1;
        for (int k = 1; k <= min(2ll, i); k++){
            C[i][k] = C[i - 1][k - 1] + C[i - 1][k];
        }
    }

    int t = 1;
    cin >> t;
    while (t--)
    {
        int k; cin >> k;
        vector<pair<int, int>> v;
        
        int n = 0;
        int cntx = 0, cnty = 0;
        do {
            int l = 0, r = 500;
            int x = 0;
            while (l <= r)
            {
                int m = (l+r)/2;
                if (C[m][2] <= k) {
                    x = m;
                    l = m+1;
                } else {
                    r = m-1;
                }
            }

            n += x;
            k -= C[x][2];
            for (int i = 0; i < x; i++)
                v.push_back({cntx, cnty++});

            cntx++;
        } while (n + k > 500);

        // cout << "n: " << n << " k: " << k << '\n';

        cout << n + k << '\n';
        for (auto p : v)
            cout << p.first << " " << p.second << '\n';
        // for k
        for (int i = 0; i < k; i++)
            cout << cntx++ << " " << i << '\n';
    }
    return 0;
}