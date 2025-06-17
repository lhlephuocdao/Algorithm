#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
int n;
vector<int> h(maxn), sign(maxn, 0);
vector<vector<int>> w(maxn, vector<int>(maxn, 0));
const int sig[2] = {-1, 1};
int ans = INT_MAX;

void backtrack(int pos)
{
    if (pos == n+1)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
            res += h[i] * sign[i];

        for (int i = 1; i < n; i++)
            for (int j = i+1; j <= n; j++)
                res += w[i][j]*sign[i]*sign[j];

        ans = min(res, ans);
        return;
    }

    for (int i = 0; i <= 1; i++)
    {
        sign[pos] = sig[i];
        backtrack(pos+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            cin >> w[i][j];

    backtrack(1);
    cout << ans << '\n';

    return 0;
}