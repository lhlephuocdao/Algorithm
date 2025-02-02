#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n-1;
    while (l<r)
    {
        int sum = a[l] + a[r];
        if (sum == x) {
            cout << l+1 << " " << r+1 << '\n';
            return 0;
        } else if (sum > x) r--;
        else l++;
    }

    cout << "No solution\n";

    return 0;
}