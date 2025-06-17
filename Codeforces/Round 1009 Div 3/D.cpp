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

int count(int x0, int r) {
    int count = 0;
    int rs = r * r;

    for (int x = x0 - r; x <= x0 + r; ++x) {
        int maxY = (int)(sqrt(rs - (x - x0) * (x - x0)));

        count += (2 * maxY + 1);
    }

    return count;
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> x(n);
        map<int, int> mp;
        for (auto& k : x) cin >> k;
        for (int i = 0; i < n; i++) {
            int r; cin >> r;
            mp[x[i]] = max(mp[x[i]], r);
        }

        // for (auto it : mp)
        //     cout << it.first << " " << it.second << '\n';

        vector<pii> c;
        for (auto it : mp)
            c.push_back({it.first, it.second});

        int sz = c.size();
        int ans = 0;
        map<int, int> m2;
        for (int i = 0; i < sz; i++) {
            int x0 = c[i].first;
            int r = c[i].second;
            for (int x = x0 - r; x <= x0 + r; ++x) {
                int maxY = (int)(sqrt(r*r - (x - x0) * (x - x0)));
        
                m2[x] = max(m2[x], 2 * maxY + 1);
            }
        }
        
        for (auto it : m2)
            ans += it.second;
            
        cout << ans << '\n';
    }

    return 0;
}