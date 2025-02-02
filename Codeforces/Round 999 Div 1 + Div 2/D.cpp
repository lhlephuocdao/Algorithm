#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 998244353;

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

    int t; cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        priority_queue<int> a, b;
        int sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push(x);
            sum_a += x;
        }

        for (int i = 0; i < m; i++) {
            int y; cin >> y;
            b.push(y);
            sum_b += y;
        }

        if (sum_a != sum_b) {
            cout << "No\n";
            continue;
        }

        int k = n-m;
        bool ans = true;
        while (!a.empty() && !b.empty() && k > 0)
        {
            int va = a.top(), vb = b.top();
            if (va == vb) {
                a.pop();
                b.pop();
            } else {
                b.pop();
                int x = vb/2, y = (vb+1)/2;
                b.push(x);
                b.push(y);
                k--;
            }
        }

        if (a.size() != b.size())
            ans = false;
        else {
            while (!a.empty()) {
                if (a.top() != b.top()) {
                    ans = false;
                    break;
                }
                a.pop();
                b.pop();
            }
        }

        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}