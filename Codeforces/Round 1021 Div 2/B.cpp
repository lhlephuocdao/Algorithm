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
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> m;
        for (auto& x : a) cin >> x, m[x]++;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int sz = a.size();

        if (sz == 1) {
            cout << 1 << '\n';
            continue;
        }

        vector<int> pre(sz, 0);
        pre[0] = m[a[0]];
        for (int i = 1; i < sz; i++)
            pre[i] = pre[i-1] + m[a[i]];
        // for (auto x : pre) cout << x << ' ';

        int ans = 0;
        bool prev = false; // take prev right trước đó hay chưa
        for (int i = 0; i < sz-1; i++) {
            int x = a[i], y = a[i+1];
            int cntx = pre[i], cnty = pre[sz-1] - pre[i];

            if (abs(cntx - cnty) <= k) {
                // case từ [x, y] -> đánh dấu đã take right bound
                cout << "y: " << y << " x: " << x << '\n';
                ans += y-x+1;
                if (prev) ans--;
                prev = true;
            }

            if (cntx>cnty && cntx-k == cnty+1) { // lấy only x
                cout << "take: " << x << '\n';
                if (!prev) ans++;
                prev = false;
            } else if (cnty-k == cntx+1) { // lấy only y
                cout << "take: " << y << '\n';
                ans++;
                prev = true;
            }

            // cout << "ans: " << ans << '\n';
        }

        // xét case a[sz-1]
        

        cout << ans << '\n';
    }
    return 0;
}