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
        int ans = 0, nums_even = 0;
        for (auto& x : a) {
            cin >> x;
            if (x % 2 == 0) nums_even++;
        }

        int nums_odd = n-nums_even;

        if (nums_even > 0)
            cout << nums_odd+1 << '\n';
        else
            cout << nums_odd-1 << '\n';
    }
    return 0;
}