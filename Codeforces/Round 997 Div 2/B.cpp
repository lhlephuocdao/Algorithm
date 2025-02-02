#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug
 * stress test
 */

int32_t main()
{
    fastio;

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> count(n, 0);
        vector<set<int>> before(n);
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
            {
                if (s[j] == '1') {
                    if (i < j) {
                        count[i]++;
                        before[j].insert(i);
                    } else {
                        count[j]++;
                        before[i].insert(j);
                    }
                } else {
                    // no edge
                    if (i < j) {
                        // i after j -> j before i
                        before[i].insert(j);
                        count[j]++;
                    } else {
                        // i before j
                        count[i]++;
                        before[j].insert(i);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) count[i] /= 2;
        // for (auto x : count) cout << x << " ";
        // cout << '\n';

        // for (auto x : before) {
        //     for (auto y : x) cout << y << " ";
        //     cout << '\n';
        // }

        vector<int> ans;
        queue<int> q;
        vector<bool> mark(n, false);
        for (int i = 0; i < n; i++) {
            if (count[i] == 0) {
                q.push(i);
                mark[i] = true;
            }
        }

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            ans.push_back(x);
            for (auto y : before[x]) {
                if (mark[y] == false) {
                    count[y]--;
                    if (count[y] == 0) {
                        q.push(y);
                        mark[y] = true;
                    }
                }
            }
        }

        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i]+1 << " ";
        cout << '\n';
    }
    return 0;
}

void solve(int testCase = 1)
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
 
    sort(p.begin(), p.end(), [&](const int& u, const int& v) -> bool {
        if (a[u][v] == '1') {
            return u < v;
        }
        else {
            return u >= v;
        }
    });
 
    for (int u : p) {
        cout << u + 1 << " ";
    }
    cout << "\n";
}