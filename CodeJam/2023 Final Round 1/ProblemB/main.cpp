#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxk = 1e4+7;

int n,k,a,b, s[110];
int dp[maxk][110];

/* d[k][N] Chi phí tối thiểu để đạt được K sticks of lenght 1 sau khi chọn N sticks */

void solve()
{
    memset(s, 0, sizeof(s));
    memset(dp, INT_MAX, sizeof(dp));

    cin >> n >> k >> a >> b;
    
    for (int i = 1; i <= n; i++) {
        cin >> s[i];

        //
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}