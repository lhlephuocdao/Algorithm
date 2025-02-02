#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug
 * stress test
 */

int32_t main()
{
    fastio;

    int t; cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        vector<int> x(n);
        map<int, int> m;
        int score = 0;
        for (auto& a : x) {
            cin >> a;
            if (a < k) {
                if (m[k-a] > 0) {
                    score++;
                    m[k-a]--;
                } else {
                    m[a]++;
                }
            }
        }
        cout << score << '\n';
    }
    return 0;
}