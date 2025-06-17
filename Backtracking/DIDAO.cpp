#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
int n,k;
vector<vector<int>> a(maxn, vector<int>(maxn));
vector<int> best, cur;
int bestSum = 1e9;
vector<bool> visited(maxn, false);

void calc(int pos, int m, int curSum)
{
    if (m == 0) {
        curSum += a[pos][0];
        if (curSum < bestSum) {
            bestSum = curSum;
            best.clear();
            for (int x : cur) best.push_back(x);
        }
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (visited[i] == true) continue;
        visited[i] = true;

        curSum += a[pos][i];
        cur.push_back(i);

        if (curSum < bestSum)
            calc(i, m-1, curSum);

        curSum -= a[pos][i];
        cur.pop_back();
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    visited[0] = true;
    cur.push_back(0);
    calc(0, k-1, 0);
    cout << bestSum << '\n';
    for (auto x : best) cout << x+1 << ' ';

    return 0;
}