#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

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

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1);
        vector<int> cnt(10, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
            if (cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[0] >= 3 && cnt[5] >= 1) {
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}