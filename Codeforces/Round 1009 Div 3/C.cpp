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

int get(int n) {
    int cnt = 0;
    while (n > 0) {
        n/=2;
        cnt++;
    }

    return cnt;
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int x; cin >>x;
        int xx = x;

        if (x <= 4) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> bx;

        while (x > 0) {
            bx.push_back(x % 2);
            x /= 2;
        }

        reverse(bx.begin(), bx.end());
        int n = bx.size();

        bool check = false;
        for (auto a : bx) {
            if (a == 0) {
                check = true;
                break;
            }
        }

        if (!check) {
            cout << -1 << '\n';
            continue;
        }

        if ((xx & ~(1<<(n-1))) == 0) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> by(n);
        by[0] = 0;
        for (int j = 1; j < n; j++)
            by[j] = 1;
        int y = 0;
        for (int j = 0; j < n; j++)
            y = y*2 + by[j];

        cout << y << '\n';
    }

    return 0;
}