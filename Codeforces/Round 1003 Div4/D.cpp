#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<vector<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<int>& a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

void debug(vector<pair<int, int>>& a)
{
    for (auto x : a)
        cout << x.first << ' ' << x.second << '\n';
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<pair<int, int>> sum(n, {0, 0});
        for (int i = 0; i < n; i++)
        {
            int s = 0, pre = 0;
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                s += a[i][j];
                pre += s;
            }
            sum[i] = {s, pre};
        }
        
        sort(sum.begin(), sum.end(), [&](pair<int, int>& a, pair<int, int>& b){
            return a.first > b.first;
        });

        // debug(sum);

        int ans = sum[0].second;
        int acc_sum = 0;
        for (int i = 1; i < n; i++)
        {
            acc_sum += sum[i-1].first;
            // cout << "accumulate sum: " << acc_sum << " " << sum[i].second << '\n';
            ans += acc_sum*m + sum[i].second;
        }
        cout << ans << '\n';
    }
    return 0;
}