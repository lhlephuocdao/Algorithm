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
    cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> pre(n+1, 0);
        for (int i = 1; i <= n; i++)
            if (a[i] <= k) pre[i] = pre[i-1] + 1;
            else pre[i] = pre[i-1];

        int l = 1;
        while (l<=n-2 && pre[l] < (l+1)/2) l++;
        int x = pre[l];

        while (l+1<=n-2 && x >= (l+2)/2 && a[l+1] > k) l++;

        int r = l+1;
        int y = pre[r] - pre[l];
        int z = pre[n] - pre[r];
        while (r<n && y < (r-l+1)/2 && z < (n-r+1)/2) {
            r++;
            y = pre[r] - pre[l];
            z = pre[n] - pre[r];
        }
        bool check1 = false;
        if (l<=n-2 && r<n) check1 = true;

        reverse(a.begin()+1, a.end());
        pre[0] = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] <= k) pre[i] = pre[i-1] + 1;
            else pre[i] = pre[i-1];

        l = 1;
        while (l<=n-2 && pre[l] < (l+1)/2) l++;
        x = pre[l];

        while (l+1<=n-2 && x >= (l+2)/2 && a[l+1] > k) l++;

        r = l+1;
        y = pre[r] - pre[l];
        z = pre[n] - pre[r];
        while (r<n && y < (r-l+1)/2 && z < (n-r+1)/2) {
            r++;
            y = pre[r] - pre[l];
            z = pre[n] - pre[r];
        }
        bool check2 = false;
        if (l<=n-2 && r<n) check2 = true;

        if (check1 || check2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}