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
        string s;
        cin >> s;
        vector<int> A, B;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') {
                A.push_back(i+1);
            } else {
                B.push_back(i+1);
            }
        }

        function<bool(int, int)> f = [&](int x, int y){
            if (x == 1 && y == n) return true;
            if (x == n && y == 1) return false;
            return x > y;
        };

        bool check = false;
        for (int a : A) {
            bool ok = true;
            for (int b : B) {
                if (f(b, a)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                check = true;
                break;
            }
        }
        cout << (check ? "Alice\n" : "Bob\n");
    }
    return 0;
}