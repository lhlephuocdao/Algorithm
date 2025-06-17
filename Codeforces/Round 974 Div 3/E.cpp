#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<int>& a){
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
        int n, m, h;
        cin >> n >> m >> h;
        vector<bool> horse(n, false);
        for (int i = 0; i < h; i++)
        {
            int a; cin >> a;
            a--;
            horse[a] = true;
        }

        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; i++)
        {
            int u,v,w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> d1(n, INT_MAX);
        vector<bool> visited(n, false);
        d1[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        bool has_horse = false;
        while (!pq.empty())
        {
            int u = pq.top().first;
            int dis = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            for (auto e : adj[u]) {
                int v = e.first;
                int w = e.second;

                if (horse[u] || has_horse) {
                    w /= 2;
                    has_horse = true;
                }
                if (d1[v] > d1[u] + w) {
                    d1[v] = d1[u] + w;
                    cout << "d1[" << v << "]: " << d1[v] << '\n';
                    pq.push({v, d1[v]});
                }
            }
        }

        if (visited[n-1] == false) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> d2(n, INT_MAX);
        vector<bool> visited2(n, false);
        d2[n-1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        pq2.push({n-1, 0});

        has_horse = false;
        while (!pq2.empty())
        {
            int u = pq2.top().first;
            int dis = pq2.top().second;
            pq2.pop();

            if (visited2[u]) continue;
            visited2[u] = true;

            for (auto e : adj[u]) {
                int v = e.first;
                int w = e.second;

                if (horse[u] || has_horse) {
                    w /= 2;
                    has_horse = true;
                }
                
                if (d2[v] > d2[u] + w) {
                    d2[v] = d2[u] + w;
                    cout << "d2[" << v << "]: " << d2[v] << '\n';
                    pq2.push({v, d2[v]});
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, max(d1[i], d2[i]));

        cout << ans << '\n';
    }
    return 0;
}