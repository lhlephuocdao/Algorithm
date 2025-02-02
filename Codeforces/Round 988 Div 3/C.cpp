#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    int t; cin >> t;
    
    const int maxn = 2e5;
    vector<bool> is_prime(maxn + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= maxn; i++)
    {
        if (is_prime[i]) {
            for (int j = i*i; j <= maxn; j += i)
                is_prime[j] = false;
        }
    }

    while (t--)
    {
        int n; cin >> n;
        if (n <= 4) {
            cout << -1 << '\n';
        } else {
            for (int i = 1; i <= n; i += 2)
                if (i != 5) cout << i << " ";

            cout << 5 << " " << 4 << " ";
            for (int i = 2; i <= n; i += 2)
            {
                if (i == 4) continue;
                cout << i << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}