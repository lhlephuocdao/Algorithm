#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

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
       int n,k,x;
       cin >> n >> k >> x;
       vector<int> a(n);
       for (auto& i : a) cin >> i;
        vector<int> suf(n, 0);
        suf[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--)
            suf[i] = suf[i+1] + a[i];

        int ans = 0;
        bool check = false;
        for (int i = n-1; i >= 0; i--) {
            if (suf[i] >= x) {
                ans = n*k - (n - i - 1);
                check = true;
                break;
            }
        }

        if (!check) {
            int s = suf[0];
            int m = (x+s-1)/s;

            // cout << "s: " << s << " m: " << m << '\n';

            if (m <= k) {
                int dif = x - (m-1)*s;

                int y = 0;
                for (int i = n-1; i >= 0; i--) {
                    if (suf[i] >= dif) {
                        y = n-i-1;
                        break;
                    }
                }
                ans = k*n - ((m-1)*n + y);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}