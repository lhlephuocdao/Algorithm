#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;
const int INF = 1e18;

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

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        vector<int> pre(n), suf(n);
        pre[0] = 0;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1];
            if (a[i] < a[pre[i-1]])
                pre[i] = i;
        }

        suf[n-1] = n-1;
        for (int i = n-2; i >= 0; i--) {
            suf[i] = suf[i+1];
            if (a[i] > a[suf[i+1]])
                suf[i] = i;
        }

        // cout << "pre: ";
        // for (auto x : pre) cout << x << ' ';
        // cout << '\n';
        // cout << "suf: ";
        // for (auto x : suf) cout << x << ' ';
        // cout << '\n';

        function<int(void)> check = [&](){
            int ans = 0;
            int i = 0, j = 0;
            while (i+j < n) {
                if (a[i] > b[j]) {
                    ans++;
                    i++;
                } else j++;
            }

            return ans;
        };

        int m = check();
        // cout << m << '\n';
        int l = m+1, r = n-1;
        while (l<=r) {
            int mid = (l+r)/2;
            assert(mid < n && mid > 0);
            int i = pre[mid-1];
            int j = suf[mid];
            swap(a[i], a[j]);
            int res = check();
            swap(a[i], a[j]);
            if (res >= mid) {
                m = max(m, res);
                l = mid+1;
            } else r = mid-1;
        }
        cout << m << '\n';
    }

    return 0;
}