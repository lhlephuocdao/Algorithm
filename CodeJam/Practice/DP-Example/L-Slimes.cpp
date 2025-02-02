#include <bits/stdc++.h>

using namespace std;
long long pre[410];
long long memory[410][410];

long long dp(int i, int j)
{
    if (i == j) return 0;

    if (memory[i][j] != 0) return memory[i][j];

    long long ans = LONG_LONG_MAX;
    for (int k = i; k < j; k++) {
        ans = min(ans, dp(i, k) + dp(k+1, j) + pre[j] - pre[i-1]);
        memory[i][j] = ans;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    memset(pre, 0, sizeof(pre));
    memset(memory, 0, sizeof(memory));
    int a[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    cout << dp(1, n);

    return 0;
}