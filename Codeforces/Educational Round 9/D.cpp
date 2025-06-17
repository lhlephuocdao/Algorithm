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
        int n,m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        // handle duplicated a[i]
        map<int, int> mp;
        for (auto& x : a)
            if (x<=m)
                mp[x]++;
        
        vector<bool> done(m+1, false);
        vector<int> cnt(m+1, 0);
        // if n = 1e6, m = 1e6
        // all a[i] = 1 -> O(n*m) = 1e12 -> TLE
        // ignore a[i] = 1
        for (int i = 0; i < n; i++) {
            if (a[i] != 1 && a[i] <= m && done[a[i]] == false) {
                for (int j = a[i]; j <= m; j+=a[i])
                    cnt[j] += mp[a[i]];
                done[a[i]] = true;
            }
        }
        int k = 0, l = 1;
        for (int i = 0; i <= m; i++)
            if (cnt[i] > k) {
                k = cnt[i];
                l = i;
            }

        for (auto x : a) if (x == 1) k++;

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (l%a[i] == 0)
                ans.push_back(i+1);

        cout << l << ' ' << k << '\n';
        for (auto x : ans)
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}