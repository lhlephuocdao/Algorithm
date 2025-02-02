#include <bits/stdc++.h>

using namespace std;

const int _max = 3000;
string s, t;

/*
    dp[i][j] : max length of a subsequence ends at s[i] and t[j]
*/

int dp[_max+1][_max+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s >> t;
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < t.length(); j++)
        {
            if (j == 0 || i == 0) {
                dp[i][j] = (s[i] == t[j]) ? 1 : 0;
                if (i > 0) dp[i][j] = max(dp[i-1][j], dp[i][j]);
                else if (j > 0) dp[i][j] = max(dp[i][j-1], dp[i][j]);
                continue;
            }

            if (s[i] == t[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));

        }
    }

    int n = s.length()-1, m = t.length()-1;
    string ans = "";

    while (n >= 0 && m >= 0)
    {
        if (s[n] == t[m]) {
            ans += s[n];
            n--;
            m--;
        } else {
            if (n>0 && m>0)
            {
                if (dp[n-1][m] > dp[n][m-1]) {
                    n--;
                } else {
                    m--;
                }
            } else if (n>0) {
                n--;
            } else if (m>0) {
                m--;
            } else break;
        }
    }

    if (!ans.empty()) reverse(ans.begin(), ans.end());
    cout << ans << '\n';

    return 0;
}