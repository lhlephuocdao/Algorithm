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
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        int i = 0, j = 0;
        int l = 0, r = 0;
        int ans = 1;
        map<int, int> mp;
        for (; j < n; j++)
        {
            mp[a[j]]++;
            if (mp.size() <= k && (j-i+1) > ans) { 
                l = i;
                r = j;
                ans = j-i+1;
            }

            while (i<=j && mp.size() > k)
            {
                mp[a[i]]--;
                if (mp[a[i]] == 0) mp.erase(mp.find(a[i]));
                i++;
            }
        }
        cout << l+1 << ' ' << r+1 << '\n';
    }
    return 0;
}