#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0;
    long long sumA = a[0], sumB = b[0];
    int ans = 0;
    while (i < n && j < m)
    {
        if (sumA == sumB) {
            ans++;
            i++;
            j++;
            if (i<n) sumA = a[i];
            if (j<m) sumB = b[j];
        } else if (sumA < sumB) {
            i++;
            if (i<n) sumA += a[i];
        } else {
            j++;
            if (j<m) sumB += b[j];
        }
    }

    if (ans==0 || i<n || j<m)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}