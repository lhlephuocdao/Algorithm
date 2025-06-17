#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

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
        int n,m,k;
        cin >> n >> m >> k;
        int x = min(n - m*k, k);

        if (n-m*k > k) {
            int a = n-m*k;
            a -= k;
            x += a/(m+1);
        }
        
        int nums = m+1;
        int remain = n - nums*x; // n - (m+1)*k > 0

        int xx = remain/m, ex = remain%m;
        // cout << "x: " << x << " nums: " << nums << " remain: " << remain << " xx: " << xx << " ex: " << ex << '\n'; 
        vector<int> ans;
        for (int j = 0; j < nums; j++)
        {
            for (int i = 0; i < x; i++)
                ans.push_back(i);

            if (j != nums-1) {
                for (int i = 0; i < xx; i++) ans.push_back(x);
                if (ex>0) ans.push_back(x), ex--;
            }
        }
        
        for (auto i : ans)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}