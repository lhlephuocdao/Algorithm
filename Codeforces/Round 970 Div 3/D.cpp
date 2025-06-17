#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> p(n+1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        string s;
        cin >> s;
        s = ' ' + s;

        vector<int> f(n+1, 0);
        vector<bool> visited(n+1, false);

        function<void(int, int&)> dfs = [&](int u, int& cnt){
            if (visited[u]) return;
            visited[u] = true;

            if (s[u] == '0') cnt++;
            dfs(p[u], cnt);

            f[u] = cnt;
        };

        for (int i = 1; i <= n; i++)
            if (visited[i] == false) {
                int x = 0;
                dfs(i, x);
            }

        for (int i = 1; i <= n; i++)
            cout << f[i] << ' ';
        cout << '\n';
    }
    return 0;
}