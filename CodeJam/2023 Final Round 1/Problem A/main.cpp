#include <bits/stdc++.h>

using namespace std;

int n,m;
int d[10][10];
int ans = 0, cnt = 0, m_value = 0;

void backtracking(int index, vector<int>& tmp, vector<bool>& mark)
{
    for (int i = 0; i < n; i++)
    {
        if (mark[i]) {
            tmp[index] = i;
            if (index == n-1) {
                int sum = 0;
                for (int u = 0; u < n; u++)
                    for (int v = u+1; v < n; v++)
                        sum += d[tmp[u]][tmp[v]];

                if (sum > m_value) {
                    m_value = sum;
                    cnt = 1;
                } else if (sum == m_value) cnt++;
            } else {
                mark[i] = false;
                backtracking(index+1, tmp, mark);
                mark[i] = true;
            }
        }
    }
}

void solve()
{
    memset(d, 0, sizeof(d));
    ans = 0; cnt = 0; m_value = 0;

    cin >> n >> m;
    vector<bool> mark(n, true);
    vector<int> tmp(n, 10);
    while (m--)
    {
        int v, a, b;
        cin >> v >> a >> b;
        a--; b--;
        d[a][b] += v;
    }

    backtracking(0, tmp, mark);

    cout << m_value << " " << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}