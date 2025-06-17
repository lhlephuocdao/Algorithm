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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int d = a[i] + 1;
            m[d]++;
        }
        vector<int> days;
        for (auto& x : m) {
            int d = x.first;
            int count = x.second;
            if (count > 0) {
                days.push_back(d);
            }
        }
        sort(days.begin(), days.end());
        bool ok = true;
        for (int i = 0; i < days.size(); ) {
            int start = i;
            while (i < days.size() && (i == start || days[i] == days[i-1] + 1)) {
                i++;
            }
            int end = i - 1;
            if (start > end) continue;
            vector<int> p(days.begin() + start, days.begin() + end + 1);
            int k = p.size();
            int max_m = 0;
            for (int d : p) {
                max_m = max(max_m, m[d]);
            }
            if (max_m >= 4) {
                continue;
            }
            if (k >= 2 && m[p[0]] >= 2 && m[p[k-1]] >= 2) {
                continue;
            }
            ok = false;
            break;
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}