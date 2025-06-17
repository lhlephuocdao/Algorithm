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
// 4=up-left, 5=down-right, 6=up-right, 7=down-left
int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

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

    int tc = 1;
    while (tc--)
    {
        int n; cin >> n;
        vector<int> h(n);
        for (auto& x : h) cin >> x;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        set<int> s;
        for (int i = 0; i < n; i++) {
            pq.push({h[i], i});
            s.insert(i);
        }

        assert(pq.size() == n);
        assert(s.size() == n);

        bool first = true;
        function<int(int,int)> get = [&](int cur_idx, int new_idx){
            int i = 0, j = 0, cnt = 0;
            for (auto itr = s.begin(); itr != s.end(); itr++, cnt++)
                if (*itr == cur_idx) i = cnt;
                else if (*itr == new_idx) j = cnt;
            int diff = abs(j-i);
            if (first) return diff+1;
            else return diff;
        };

        int ans = 0, cur_idx = 0;
        while (!pq.empty()) {
            int next_idx = pq.top().second;
            pq.pop();

            ans += get(cur_idx, next_idx);
            if (first == false) {
                s.erase(cur_idx);
            } else first = false;

            cur_idx = next_idx;
        }

        cout << ans << '\n';
    }

    return 0;
}