#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 998244353;

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug :
 *      - duplicated element
 *      - consecutive range: 1 2 3 4 5 ....
 * stress test
 */

int32_t main()
{
    fastio;

    int t; cin >> t;
    while (t--)
    {
        int n,l,r;
        cin >> n >> l >> r;
        l--; r--;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        int min_left = 0, min_right = 0;
        vector<int> left, right;
        for (int i = 0; i <= r; i++)
            left.push_back(a[i]);

        sort(left.begin(), left.end());
        for (int i = 0; i < r-l+1; i++)
            min_left += left[i];

        for (int i = l; i < n; i++)
            right.push_back(a[i]);

        sort(right.begin(), right.end());
        for (int i = 0; i < r-l+1; i++)
            min_right += right[i];

        cout << min(min_left, min_right) << '\n';
    }
    return 0;
}