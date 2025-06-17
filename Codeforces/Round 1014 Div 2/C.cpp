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
        int n;
        cin >> n;
        int s = 0, odd = 0, _max = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
            _max = max(_max, a[i]);
            if(a[i] & 1) odd++;
        }
        
        if(odd == 0 || odd == n){
            cout << _max << "\n";
        }
        else{
            cout << (s - odd + 1) << "\n";
        }
    }

    return 0;
}