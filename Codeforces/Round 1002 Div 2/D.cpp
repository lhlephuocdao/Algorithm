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

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,s1,s2,m1,m2;
        cin >> n >> s1 >> s2;
        s1--; s2--;
        vector<vector<int>> g1(n), g2(n);
        vector<vector<bool>> check(n, vector<bool>(n, false));
        set<int> candidate;
        cin >> m1;
        for (int i = 0; i < m1; i++)
        {
            int a,b;
            cin >> a >> b;
            a--; b--;
            g1[a].push_back(b);
            g1[b].push_back(a);
            check[a][b] = true;
            check[b][a] = true;
        }

        cin >> m2;
        for (int i = 0; i < m2; i++)
        {
            int c,d;
            cin >> c >> d;
            c--; d--;
            g2[c].push_back(d);
            g2[d].push_back(c);
            if (check[c][d]) {
                candidate.insert(c);
                candidate.insert(d);
            }
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {s1, s2}});

        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        dis[s1][s2] = 0;

        while (!pq.empty())
        {
            int v1 = pq.top().second.first;
            int v2 = pq.top().second.second;
            int dis_v1v2 = pq.top().first;
            pq.pop();

            for (auto u1 : g1[v1])
                for (auto u2 : g2[v2]) {
                    int w = abs(u1 - u2);
                    if (dis[u1][u2] > w + dis[v1][v2]) {
                        dis[u1][u2] = w + dis[v1][v2];
                        pq.push({dis[u1][u2], {u1, u2}});
                    }
                }
        }

        int ans = INT_MAX;
        for (auto x : candidate)
            ans = min(ans, dis[x][x]);

        if (ans == INT_MAX)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}