#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 998244353;
#define sc second
#define fi first
#define all(x) x.begin(), x.end()

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
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        function<bool(int)> check = [&](int m){
            if (m == 0) return true;
            int cnt = 0;
            int mex = 0;
            int i = 0;
            vector<int> f(m, 0);
            while (i < n) {
                if (a[i] < m) f[a[i]]++;
                while (mex < m && f[mex] != 0) mex++;
                if (mex == m) {
                    cnt++;
                    fill(all(f), 0);
                    mex = 0;
                }
                i++;
            }

            return cnt >= k;
        };

        int ans = 0;
        int l = 0, r = n;
        while (l <= r) {
            int mid = (l+r)/2;
            if (check(mid)) {
                ans = max(ans, mid);
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}