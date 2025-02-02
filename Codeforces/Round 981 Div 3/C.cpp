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
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 0;
        int i, j;
        if (n%2==1) {
            i = (n+1)/2 - 1;
            j = (n+1)/2 + 1;
        } else {
            i = n/2;
            j = n/2 + 1;
        }

        while (i>1 && j<n)
        {
            if ((a[i-1] != a[j+1]) && (a[i] == a[i-1] || a[j] == a[j+1]))
                swap(a[i-1], a[j+1]);
            i--;
            j++;
        }

        for (int i = 1; i < n; i++)
            if (a[i] == a[i+1]) ans++;
        cout << ans << '\n';
    }

    return 0;
}