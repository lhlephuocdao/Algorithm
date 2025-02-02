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
        int n,k;
        cin >> n >> k;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            m[a]++;
        }

        int sz = m.size();
        vector<pair<int, int>> pa;
        for (auto itr : m) pa.push_back({itr.first, itr.second});
        int count = 0, ans = 0;
        vector<int> pre(sz, 0);
        for (int i = 0; i < sz; i++)
        {
            if (i == 0) {
                count++;
                pre[i] = pa[i].second;
                ans = max(ans, pre[i]);
            } else {
                if (pa[i].first - pa[i-1].first > 1) {
                    count = 1;
                    pre[i] = pa[i].second;
                    ans = max(ans, pre[i]);
                } else {
                    pre[i] = pre[i-1] + pa[i].second;
                    if (count+1 <= k) {
                        count++;
                        ans = max(ans, pre[i]);
                    } else {
                        ans = max(ans, pre[i] - pre[i-k]);
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}