#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n-2; i++)
    {
        if (a[i] >= m) break;
        int l = i+1, r = n-1;
        while (l<r) {
            int sum = a[i] + a[l] + a[r];
            if (sum == m) {
                cout << m << '\n';
                return 0;
            } else if (sum < m) {
                ans = max(ans, sum);
                l++;
            } else r--;
        }
    }

    cout << ans << '\n';

    return 0;
}