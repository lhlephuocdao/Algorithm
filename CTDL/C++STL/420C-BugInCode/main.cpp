#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long

const int maxn = 3e5 + 7;

int n,p;
int c[maxn];
vector<int> v;
ll ans = 0;

void solve()
{
    cin >> n >> p;
    memset(c, 0, sizeof(c));
    vector<vector<int>> adj(n+1);
    for (int i = 1; i <= n; i++) c[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        c[x]++;
        c[y]++;
    }

    for (int i = 1; i <= n; i++)
        v.push_back(c[i]);
    
    sort(v.begin(), v.end());
    int size = v.size();

    for (int i = 1; i <= n; i++)
    {
        int need = p - c[i];
        int index = lower_bound(v.begin(), v.end(), need) - v.begin();
        int add = size - index;
        if (need <= c[i]) add--;

        vector<int> a = adj[i];
        for (auto j : a)
        {
            c[j]--;
            if (c[j] == need-1) add--;
        }

        for (auto j : a) c[j]++;

        ans += add;
    }

    ans /= 2;

    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}