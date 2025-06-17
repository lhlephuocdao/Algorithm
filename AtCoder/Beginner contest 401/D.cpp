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
        string s, ans;
        cin >> s;
        vector<bool> free(n, true);
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                free[i] = false;
                if (s[i] == 'o' && k > 0) k--;
            } else {
                // s[i] = ?
                bool check = true;
                if (i>0 && s[i-1] == 'o') check = false;
                if (i<n-1 && s[i+1] == 'o') check = false;
                free[i] = check;  
            }
        }

        if (k == 0) {
            for (int i = 0; i < n; i++)
                if (s[i] == '?' || s[i] == '.')
                    ans += '.';
                else
                    ans += 'o';
            cout << ans << '\n';
            continue;
        }
        
        bool pos = false;
        int j = 0;
        int total = 0;
        while (j<n) {
            if (free[j] == false) {
                j++;
                continue;
            }
            int cnt = 0;
            while (j<n && free[j]) cnt++, j++;

            total += (cnt+1)/2;
        }

        if (total > k)
            pos = true;

        int i = 0;
        while (i < n)
        {
            if (s[i] == 'o') ans += 'o', i++;
            else if (s[i] == '.') ans += '.', i++;
            else {
                if (free[i] == false) {
                    ans += '.';
                    i++;
                } else {
                    if (pos) {
                        ans += '?';
                        i++;
                    } else {
                        int cnt = 0;
                        while (i<n && free[i]) cnt++, i++;
                        if (cnt&1) { //odd -> o.o.o.o
                            for (int x = 0; x < cnt; x++)
                                if (x&1)
                                    ans += '.';
                                else
                                    ans += 'o';
                        } else { //even -> o.o.o. or .o.o.o
                            for (int x = 0; x < cnt; x++)
                                ans += '?';
                        }
                    }
                }
            }
        }
        assert(ans.length() == n);
        cout << ans << '\n';
    }
    return 0;
}