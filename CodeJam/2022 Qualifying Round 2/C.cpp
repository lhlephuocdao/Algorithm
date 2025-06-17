#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 987654323;
const int INF = 1e18;

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

class Compare {
public:
	bool operator()(pii a, pii b) {
		if (a.first != b.first) return a.first < b.first;
        else return a.second > b.second;
	}
};

int32_t main()
{
    fastio;

    int tc = 1; cin >> tc;
    while (tc--)
    {
        int n; cin >> n;
        vector<int> v(n);
        int m = 0;
        priority_queue<pii, vector<pii>, Compare> pq;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            pq.push({v[i], i});
            m += v[i];
        }
        vector<int> ans(m);
        int even = (m+1)/2, odd = m-even;
        int i_even = 0, i_odd = 1;
        int idv = 0;

        if (even < pq.top().first) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        while (i_even < m || i_odd < m) {
            assert(pq.empty() == false);
            int even_cap = even - i_even/2;
            int odd_cap = odd - i_odd/2;
            int capacity = max(even_cap, odd_cap);
            int max_v = pq.top().first;
            int idx_max_v = pq.top().second;
            if (max_v > v[idx_max_v]) {
                pq.pop();
                pq.push({v[idx_max_v], idx_max_v});
                max_v = pq.top().first;
                idx_max_v = pq.top().second;
            }
            cout << "even_cap: " << even_cap << '\n';
            cout << "odd_cap: " << odd_cap << '\n';
            cout << "i_even: " << i_even << '\n';
            cout << "i_odd: " << i_odd << '\n';
            cout << "max_v : " << max_v << " capacity : " << capacity << '\n';
            cout << "v[" << idv << "] : " << v[idv] << '\n';
            if (max_v < capacity) {
                while (idv < n && v[idv] == 0) idv++;
                if (i_even < i_odd) {
                    ans[i_even] = idv;
                    i_even += 2;
                } else {
                    ans[i_odd] = idv;
                    i_odd += 2;
                }
                v[idv]--; // Need to update priority queue at here
            } else {
                assert(max_v == capacity);
                
                pq.pop();
                cout << "idx_max_v : " << idx_max_v << '\n';
                

                if (even_cap > odd_cap || (even_cap == odd_cap && i_even < i_odd)) {
                    // fill from even
                    while (i_even < m && max_v > 0) {
                        ans[i_even] = idx_max_v;
                        max_v--;
                        v[idx_max_v]--;
                        i_even += 2;
                    }
                } else {
                    assert(even_cap < odd_cap || (even_cap == odd_cap && i_even > i_odd));
                    while (i_odd < m && max_v > 0) {
                        ans[i_odd] = idx_max_v;
                        max_v--;
                        v[idx_max_v]--;
                        i_odd += 2;
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            cout << ans[i]+1 << ' ';
            res += (i+1)*(ans[i]+1);
            res %= mod;
        }
        cout << '\n';
        cout << res << '\n';
    }
    return 0;
}