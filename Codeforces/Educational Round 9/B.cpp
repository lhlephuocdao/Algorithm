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
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        string s;
        cin >> s;
        vector<int> preA(n), preB(n), sufA(n), sufB(n);
        if (s[0] == 'A') {
            preA[0] = a[0];
            preB[0] = 0;
        } else {
            preA[0] = 0;
            preB[0] = a[0];
        }

        if (s[n-1] == 'A') {
            sufA[n-1] = a[n-1];
            sufB[0] = 0;
        } else {
            sufA[n-1] = 0;
            sufB[n-1] = a[n-1];
        }

        for (int i = 1; i < n; i++)
        {
            if (s[i] == 'A') {
                preA[i] = preA[i-1] + a[i];
                preB[i] = preB[i-1];
            } else {
                preA[i] = preA[i-1];
                preB[i] = preB[i-1] + a[i];
            }
        }

        for (int i = n-2; i >= 0; i--)
        {
            if (s[i] == 'A') {
                sufA[i] = sufA[i+1] + a[i];
                sufB[i] = sufB[i+1];
            } else {
                sufA[i] = sufA[i+1];
                sufB[i] = sufB[i+1] + a[i];
            }
        }

        int ans = max(preB[n-1], preA[n-1]);
        for (int i = 0; i < n-1; i++) {
            ans = max(ans, preB[i] + sufA[i+1]);
            ans = max(ans, preA[i] + sufB[i+1]);
        }
        cout << ans << '\n';
    }
    return 0;
}