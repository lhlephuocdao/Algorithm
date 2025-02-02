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
        int n, k; cin >> n >> k;
        if (n == 1 || k == (n+1)/2) {
            cout << 1 << '\n';
            cout << 1 << '\n';
        } else if (k == n || k == 1) {
            cout << -1 << '\n';
        } else if (k > (n+1)/2){
            int diff  = n-k;
            if (diff % 2 == 0) {
                cout << 5 << '\n';
                cout << 1 << " " << 2 << " " << k << " " << k+1 << " " << k+2 << '\n';
            } else {
                cout << 3 << '\n';
                cout << 1 << " " << k << " " << k+1 << '\n';
            }
        } else {
            int diff = k-1;
            if (diff%2 == 0) {
                cout << 5 << '\n';
                cout << 1 << " " << 2 << " " << k << " " << k+1 << " " << k+2 << '\n';
            } else {
                cout << 3 << '\n';
                cout << 1 << " " << k << " " << k+1 << '\n';
            }
        }
    }

    return 0;
}