#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug
 * stress test
 */

int32_t main()
{
    fastio;

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        bool ans = true;
        for (int i = 0; i < n-1; i++)
        {
            if (a[i] <= a[i+1]) {
                a[i+1] -= a[i];
                a[i] = 0;
            }
        }

        // for (auto x : a) cout << x << " ";
        // cout << '\n';

        for (int i = 0; i < n-1; i++)
        {
            if (a[i] > a[i+1]) {
                ans = false;
                break;
            }
        }

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}