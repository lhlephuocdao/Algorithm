#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    vector<int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i-1] + a[i];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    /*
        first : shortest distance
        second: problem i-th
    */
    pq.push({0, 0}); // take 0 distance to reach problem 0-th
    vector<int> min_dis(n, LONG_LONG_MAX);
    min_dis[0] = 0;

    while (!pq.empty())
    {
        pair<int, int> u = pq.top();
        pq.pop();
        int dis = u.first, i = u.second;

        if (i>0 && min_dis[i-1] > dis) {
            min_dis[i-1] = dis;
            pq.push({dis, i-1});
        }

        if (min_dis[b[i]] > dis + a[i]) {
            min_dis[b[i]] = dis + a[i];
            pq.push({min_dis[b[i]], b[i]});
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, pre[i] - min_dis[i]);
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}