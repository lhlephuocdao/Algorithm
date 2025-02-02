#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> m >> n >> k;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j] = s[j] - 'A';
    }

    map<int, int> mp;
    int count = 0;
    long long ans = 0;
    for (int i1 = 0, i2 = 0; i2 < m; i2++)
    {
        for (int j1 = 0, j2 = 0; j2 < n; j2++)
        {
            mp[a[i2][j2]]++;
            if (mp[a[i2][j2]] == 1) count++;

            if (count == k) ans = 0;
        }
    }

    return 0;
}