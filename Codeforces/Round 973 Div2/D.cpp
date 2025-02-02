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
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++)
        {
            int sum = a[i];
            int cnt = 1;

            while (!s.empty() && s.top().first >= sum/cnt){
                sum += s.top().first * s.top().second;
                cnt += s.top().second;
                s.pop();
            }

            int fl = floor((double)sum/(double)cnt);
            int ce = ceil((double)sum/(double)cnt);

            s.push({fl, cnt - sum%cnt});
            if (sum%cnt != 0) {
                s.push({ce, sum%cnt});
            }
        }

        int ma = s.top().first;
        while (s.size() > 1) s.pop();

        cout << ma - s.top().first << '\n';
    }

    return 0;
}