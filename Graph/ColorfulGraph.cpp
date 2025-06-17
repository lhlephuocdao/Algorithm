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

void debug(vector<set<int>>& a)
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
    // cin >> t;
    while (t--)
    {
        const int maxn = 1e5;
        int n,m;
        cin >> n >> m;
        vector<int> c(n);
        vector<set<int>> V(maxn+1);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            V[c[i]].insert(i);
        }

        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++)
        {
            int a,b;
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // debug(V);

        vector<int> ans(maxn+1, -1);
        for (int i = 1; i <= maxn; i++)
        {
            auto s = V[i];
            if (s.empty()) continue;

            set<int> st;
            for (auto x : s)
            {
                for (auto y : adj[x]) {
                    if (c[y] != i)
                        st.insert(c[y]);
                }
            }
            ans[i] = st.size();
        }

        // debug(ans);

        int res = 0, _max = -1;
        for (int i = 1; i <= maxn; i++)
        {
            if (ans[i] > _max) {
                res = i;
                _max = ans[i];
            }
        }
        cout << res << '\n';
    }
    return 0;
}