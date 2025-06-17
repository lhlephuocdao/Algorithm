#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug :
 *      - duplicated element
 *      - consecutive range: 1 2 3 4 5 ....
 * stress test
 */

int32_t main()
{
    fastio;

    int t = 1;
    // cin >> t;
    while (t--)
    {   
        int n; cin >> n;
        vector<string> name(n);
        for (auto& s : name) cin >> s;

        vector<vector<int>> g(26);
        vector<int> in(26, 0), topo;
        queue<int> q;
        bool pos = true;

        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                string s1 = name[i], s2 = name[j];
                int l1 = s1.length();
                int l2 = s2.length();
                int a = 0, b = 0;
                while (a<l1 && b<l2 && s1[a] == s2[b]) a++, b++;
                if (a<l1 && b<l2) {
                    int u = s1[a] - 'a', v = s2[b] - 'a';
                    g[u].push_back(v);
                    in[v]++;
                } else if (b == l2) {
                    pos = false;
                    break;
                }
            }
        }

        for (int i = 0; i < 26; i++)
            if (in[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (auto v : g[u]) {
                in[v]--;
                if (in[v] == 0)
                    q.push(v);
            }
        }

        if (topo.size() < 26 || !pos) {
            cout << "Impossible\n";
            return 0;
        }

        for (auto c : topo)
            cout << char(c+'a');
        cout << '\n';
    }

    return 0;
}