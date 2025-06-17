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
        const int maxc = 1e6;
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();

        int max_cost = *max_element(a.begin(), a.end()) * k;
        bitset<maxc+1> d;
        d[0] = 1;
        // chưa lấy object nào -> sum = 0 -> d[0] = 1

        for (int i = 0; i < k; i++)
        {
            bitset<maxc+1> next;
            for (int j = 0; j < n; j++) {
                // cần cộng thêm all sums hiện tại thêm a[j]
                // all sums thể hiện qua d
                // d[x] = 1 : có thể đạt x sum với i objects
                // vậy, khi add thêm a[j], chuyển state từ d[x] = 1 -> d[x+a[j]] = 1
                // x là thứ tự của bit trong bitset, để chuyển state -> dùng dịch bit sang trái
                next |= d << a[j];
            }
            d = next;
        }

        vector<int> ans;
        for (int i = 1; i <= max_cost; i++)
            if (d[i])
                ans.push_back(i);

        for (auto x : ans)
            cout << x << ' ';
    }
    return 0;
}