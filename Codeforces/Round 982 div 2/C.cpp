#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        map<int, vector<int>> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            int p = a[i] + i;
            m[p].push_back(i);
        }

        map<int, int> memory; 

        function<int(vector<int>&, int)> back = [&](vector<int>& v, int cur) -> int {
            int ans = cur;
            for (auto x : v) {
                if (x == 0) continue;
                int target = cur + x;
                if (memory[target] == 0) {
                    vector<int> fd = m[target];
                    if (!fd.empty()) {
                        int ret = back(fd, target);
                        ans = max(ans, ret);
                    } else {
                        ans = max(ans, target);
                    }
                    memory[target] = ans;
                } else {
                    ans = max(ans, memory[target]);
                }
            }
            return ans;
        };

        int sol = n;
        vector<int> init = m[n];
        if (init.empty())
            cout << sol << '\n';
        else {
            sol = back(init, sol);
            cout << sol << '\n';
        }
    }

    return 0;
}