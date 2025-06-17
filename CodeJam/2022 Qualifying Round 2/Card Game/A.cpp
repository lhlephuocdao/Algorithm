#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>
const int mod = 1e9 + 7;

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
        int n; cin >> n;
        string a,b;
        cin >> b >> a;

        int bob = 0;
        for (auto x : b) bob = bob*10 + (x - '0');
        int tmp = 0;
        for (int i = n-1; i >= 0; i--) tmp = tmp*10 + (b[i] - '0');
        bob = min(bob, tmp);

        int ans = 0;
        sort(a.begin(), a.end());
        do {
            int alice = 0;
            for (auto x : a) alice = alice*10 + (x - '0');
            if (alice < bob) ans = max(ans, alice);

        } while (next_permutation(a.begin(), a.end()));

        if (ans == 0) {
            sort(a.begin(), a.end(), greater<int>());
            a.pop_back();
            for (auto x : a) ans = ans*10 + (x-'0');
        }

        cout << ans << '\n';
    }

    return 0;
}