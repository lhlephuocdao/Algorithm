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

int32_t main()
{
    // fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int k = n*(n+1)/2;
        int sq = (int)sqrt(k);

        if (n == 1 || (sq * sq == k)) {
            cout << -1 << '\n';
        } else {
            priority_queue<int, vector<int>, greater<int>> pq;
            vector<int> ans;
            ans.push_back(2);

            for (int i = 1; i <= n; i++)
                if (i != 2) pq.push(i);

            int cur = 2;
            bool check = true;
            while (!pq.empty()) {
                int x = pq.top();

                int a = cur + x;
                int b = (int)sqrt(a);

                // cout << "cur: " << cur  << "x : " << x << " a : " << a << " b : " << b << '\n';

                if (b*b != a) {
                    ans.push_back(x);
                    pq.pop();
                    cur += x;
                } else {
                    pq.pop();
                    int y = 0;
                    if (pq.empty()) {
                        check = false;
                        break;
                    } else {
                        y = pq.top();
                        pq.pop();
                        ans.push_back(y);
                        cur += y;
                    }
                    pq.push(x);
                }
            }

            if (check) {
                for (auto i : ans) cout << i << ' ';
                cout << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}