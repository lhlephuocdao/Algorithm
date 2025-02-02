#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long

const int max_n = 15;

int dp[max_n][max_n];

int solve(string& s)
{
    int ans = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 1;
        for (int j = i+1; j < n; j++)
        {
            for (int k = 0; k <= i; k++)
                if (stoll(s.substr(k,i-k+1), nullptr, 16) <= stoll(s.substr(i+1, j-i), nullptr, 16))
                    dp[i+1][j] += dp[k][i];
        }
    }

    for (int i =0; i < n; i++)
        ans += dp[i][n-1];

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        string S;
        cin >> S;
        memset(dp, 0, sizeof(dp));
        int ans = solve(S);
        cout << ans << '\n';
    }
 
    return 0;
}