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
        int n,k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        int sum = -1;
        bool check = true;
        for (int i = 0; i < n; i++) {
            if (sum == -1) {
                if (b[i] != -1)
                    sum = a[i] + b[i];
            } else {
                if (b[i] != -1 && a[i] + b[i] != sum) {
                    check = false;
                    break;
                }
            }
        }

        // cout << "sum: " << sum << '\n';

        if (!check) {
            cout << 0 << '\n';
            continue;
        }

        if (sum == -1) {
            int a_min = INT_MAX, a_max = INT_MIN;
            for (int i = 0; i < n; i++) {
                if (b[i] == -1) {
                    a_min = min(a_min, a[i]);
                    a_max = max(a_max, a[i]);
                }
            }

            int dif = k - (a_max - a_min);
            if (dif >= 0)
                cout << dif+1 << '\n';
            else
                cout << 0 << '\n';
        } else {
            bool pos = true;
            for (int i = 0; i < n; i++) {
                if (b[i] == -1) {
                    // b[i] = sum - a[i]
                    int x = sum - a[i];
                    if (x<0 || x>k) {
                        pos = false;
                        break;
                    }
                }
            }
            if (pos) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    return 0;
}