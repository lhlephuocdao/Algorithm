#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<int>& a){
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,d,k;
        cin >> n >> d >> k;
        vector<int> a(2*n + 1, 0);
        for (int i = 0; i < k; i++)
        {
            int l,r;
            cin >> l >> r;
            a[l]++;
            a[r+d]--;
        }

        int s = 0;
        vector<int> b(2*n + 1, 0);
        for (int i = 1; i <= 2*n; i++)
        {
            s += a[i];
            b[i] = s;
        }

        int x = 0, max_x = 0, y = 0, min_y = k + 1;
        for (int i = d; i <= n; i++)
        {
            if (b[i] > max_x) {
                x = i - d + 1;
                max_x = b[i];
            }

            if (b[i] < min_y) {
                y = i - d + 1;
                min_y = b[i];
            }
        }

        cout << x << " " << y << '\n';

    }
    return 0;
}