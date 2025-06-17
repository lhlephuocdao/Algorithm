#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;

// directions: 0=up, 1=right, 2=down, 3=left
// 4=up-left, 5=down-right, 6=up-right, 7=down-left
int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

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
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> cnt(1001, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        int ans = 0, acc = 0;
        for (int i = 0; i <= 1000; i++) {
            if (cnt[i] == 0) continue;
            int num = 0;
            acc += cnt[i];
            num = cnt[i] / (i+1);
            if (cnt[i] % (i+1) != 0) num++;
            if (num * (i+1) < acc) {
                num = acc/(i+1);
                if (acc % (i+1) != 0) num++;
            }
            ans = max(ans, num);
        }
        cout << ans << '\n';
    }

    return 0;
}