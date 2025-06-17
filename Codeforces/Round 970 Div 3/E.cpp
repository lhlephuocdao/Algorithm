#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<vector<int>> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << "i: " << i << '\n';
        for (int j = 0; j < 26; j++)
        {
            char c = j + 'a';
            if (v[i][j] != 0) cout << c << " : " << v[i][j] << '\n';
        }
    }
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        vector<vector<int>> pre1(n, vector<int>(30, 0)), pre2(n, vector<int>(30, 0));

        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            int x = s[i] - 'a'; // cnt for i tang len 1. cnt for other charactors giu nguyen

            for (int j = 0; j < 26; j++) {
                if (i>0) {
                    pre2[i][j] = pre2[i-1][j];
                    pre1[i][j] = pre1[i-1][j];
                }

                if (j == x) {
                    if (i%2 == 0) pre2[i][j] += 1;
                    else pre1[i][j] += 1;
                }
            }
        }

        vector<vector<int>> suf1(n, vector<int>(30, 0)), suf2(n, vector<int>(30, 0));
        for (int i = n-1; i >= 0; i--)
        {
            int x = s[i] - 'a'; // cnt for i tang len 1. cnt for other characters giu nguyen

            for (int j = 0; j < 26; j++) {
                if (i < n-1) {
                    suf2[i][j] = suf2[i+1][j];
                    suf1[i][j] = suf1[i+1][j];
                }

                if (j == x) {
                    if (i%2 == 0) suf2[i][j] += 1;
                    else suf1[i][j] += 1;
                }
            }
        }

        int ans = n;
        if (n % 2 == 0)
        {
            int f1 = 0, f2 = 0;
            for (int j = 0; j < 26; j++)
            {
                f1 = max(f1, pre1[n-1][j]);
                f2 = max(f2, pre2[n-1][j]);
            }
            ans = min(ans, n - f1 - f2);
        } else {
            for (int i = 0; i < n; i++)
            {
                int f1 = 0, f2 = 0;
                // remove s[i]
                for (int j = 0; j < 26; j++)
                {
                    if (i > 0 && i < n-1) {
                        f1 = max(f1, pre1[i-1][j] + suf2[i+1][j]);
                        f2 = max(f2, pre2[i-1][j] + suf1[i+1][j]);
                    } else if (i == 0) {
                        // remove s[0], con lai s[1] -> s[n-1]
                        f1 = max(f1, suf2[i+1][j]);
                        f2 = max(f2, suf1[i+1][j]);
                    } else {
                        // remove s[n-1]
                        f1 = max(f1, pre1[i-1][j]);
                        f2 = max(f2, pre2[i-1][j]);
                    }
                }
                ans = min(ans, n - f1 - f2);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}