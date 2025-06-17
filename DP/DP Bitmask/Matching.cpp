#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
const int MAX_N = 21;
const int mod = 1e9 + 7;

int n;
int a[MAX_N][MAX_N];
ll _memory[MAX_N][1<<MAX_N];
int dp[1<<MAX_N];

ll solve(int cur, int toFlag, int k)
{
    // cout << "solve cur: " << cur << " toFlag: " << toFlag << " k: " << k << '\n';
    if (a[k][cur] == 0) return 0;

    ll& memo = _memory[k][toFlag];
    if (memo != -1) {
        return memo;
    }

    if (__builtin_popcount(toFlag) == 1 && k+1 == n-1) {
        int woman = __builtin_ctz(toFlag);
        // cout << "return a[" << k+1 << "][" << woman << "]: " << a[k+1][woman] << '\n';
        return a[k+1][woman];
    }

    memo = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(toFlag & (1<<i)) || a[k+1][i] == 0) continue;

        memo += solve(i, toFlag & ~(1<<i), k+1);
        memo %= mod;
    }

    return memo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    memset(a, 0, sizeof(a));
    memset(_memory, -1, sizeof(_memory));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    ll ans = 0;
    int allFlag = (1<<n)-1;
    if (n==1) ans = a[0][0];
    else 
        for (int i = 0; i < n; i++) {
            ans += solve(i, allFlag & ~(1<<i), 0);
            ans %= mod;
        }
    cout << ans << '\n';

    // memset(dp, 0, sizeof(dp));
    // dp[0] = 1;

    // for (int s = 0; s < (1<<n); ++s) // s : subset of woman that is already matched
    // {
    //     int i = __builtin_popcount(s); //number of woman that is already matched
    //     for (int j = 0; j < n; j++) // consider the woman j-th
    //     {
    //         if (!(s & (1<<j)) && a[i][j]) {
    //             dp[s | (1<<j)] += dp[s];
    //             dp[s | (1<<j)] %= mod;
    //         }
    //     }
    // }

    // cout << dp[(1<<n)-1] << '\n';

    return 0;
}
