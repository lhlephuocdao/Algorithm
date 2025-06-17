#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,k; cin >> n >> k;
        int x = n-k+1;
        if (k%2 == 0) { // k chan
            int n_odd = k/2;
            if (n_odd %2 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        } else {
            int n_odd;
            if (x%2 == 0) {
                n_odd = k/2;
            } else {
                n_odd = (k+1)/2;
            }

            if (n_odd %2 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}