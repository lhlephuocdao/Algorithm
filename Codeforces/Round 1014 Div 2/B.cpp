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
        string a,b;
        cin >> a >> b;
        int c1 = 0, c2 = 0;
        
        for (int i = 0; i < n; i++){
            if(i % 2 == 0){
                if(a[i] == '1') c1++;
                if(b[i] == '1') c2++;
            } else {
                if(b[i] == '1') c1++;
                if(a[i] == '1') c2++;
            }
        }
        
        int cap1 = n / 2;
        int cap2 = (n + 1) / 2;
        
        if(c1 <= cap1 && c2 <= cap2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}