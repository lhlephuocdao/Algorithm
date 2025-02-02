#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 16;
int N, M;
vector<int> X, Y;
bool mark[2*maxn];
ll dp[maxn][1<<maxn];

void solve()
{
    cin >> N >> M;

    memset(dp, 0, sizeof(dp));
    memset(mark, true, sizeof(mark));
    X.clear(); X.resize(N);
    Y.clear();

    for (int i = 0; i < N; i++) {
        cin >> X[i];
        mark[X[i] + N] = false;
    }

    for (int i = 0; i <= 2*N; i++)
        if (i != N && mark[i]) Y.push_back(i - N);

    dp[0][0] = 1;

    for (int s = 1; s < (1<<N); s++) // s = {j1, j2, j3, ... , jN}: subset of Y
    {
        for (int j = 0; j < N; j++)
        {
            if (!(s & (1<<j))) continue;

            int k = __builtin_popcount(s); // k-1 : index of X

            for (int i = 0; i <= min(k, M); i++) // i : Albert's points
            {
                if ((X[k-1]*Y[j] > 0 && abs(X[k-1]) > abs(Y[j])) || (X[k-1]*Y[j] < 0)) {
                    if (i>0) dp[i][s] += dp[i-1][s^(1<<j)];
                } else {
                    dp[i][s] += dp[i][s^(1<<j)];
                }
            }
        }
    }

    cout << dp[M][(1<<N)-1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("out.txt", "w", stdout);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}