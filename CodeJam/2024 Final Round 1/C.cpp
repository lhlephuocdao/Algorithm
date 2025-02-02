#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

void solve()
{
    int N,M,P,K;
    cin >> N >> M >> P >> K;
    vector<int> C(N), deg(N,0), parent(N, 0);
    vector<vector<int>> out(N);

    for (int i = 0; i < N; i++) {
        cin >> C[i];
        parent[i] = C[i];
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y; // x -> y
        --x; --y;
        out[x].push_back(y);
        deg[y]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
        if (deg[i] == 0) q.push(i);

    vector<int> nodes;
    while (!q.empty())
    {
        int root = q.front();
        nodes.push_back(root);
        q.pop();

        for (auto v : out[root])
        {
            deg[v]--;
            if (deg[v] == 0)
                q.push(v);
        }
    }

    int ans = 0;
    for (auto u : nodes)
    {
        int add = parent[u];
        if (add > K) ans += K%mod;
        else ans += add-1;
        ans %= mod;

        for (auto v : out[u]) {
            if (add >= parent[v]) {
                // parent[v] = C[v] + x*P > add
                // x > (add - C[v])/P
                int x = (add-C[v])/P + 1;
                parent[v] = C[v] + x*P;
            }
        }
    }

    for (int i = 0; i < N; i++)
        if (deg[i] > 0) {
            ans += K%mod;
            ans %= mod;
        }

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