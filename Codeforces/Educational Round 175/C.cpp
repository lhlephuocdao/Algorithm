#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> a(n);
        int maxa = 1;
        for (auto& x : a) cin >> x, maxa = max(maxa, x);

        vector<int> v;
        int i = 0;
        while (i < n)
        {
            int max_ = 0;
            int max2 = 0;
            while (i < n && s[i] == 'B') {
                max_ = max(max_, a[i]);
                i++;
            }
            if (max_ != 0) v.push_back(max_);

            if (i != 0) {
                while (i < n && s[i] == 'R') {
                    max2 = max(max2, a[i]);
                    i++;
                }
                if (i != n && max2 != 0) v.push_back(max2);
            } else {
                while (i < n && s[i] == 'R') i++;
            }
            // cout <<"i: " << i << '\n';
            // i++;
        }

        // for (auto i : v) cout << i << ' ';
        // cout << '\n';

        // v : B R B R B R B R B
        auto check = [&](int x)
        {
            int cnt = 0;
            bool is_choosing = false;
            for (int i = 0; i < v.size(); i++)
            {
                if (i%2 == 0) {
                    if (v[i] > x) {
                        if (is_choosing == false) cnt++;
                        is_choosing = true;
                    }
                } else {
                    if (is_choosing && v[i] > x)
                        is_choosing = false;
                }
            }
            return cnt <= k;
        };

        int l = 0, r = maxa;
        int ans = maxa;
        while (l <= r)
        {
            int mid = (l+r)/2;
            if (check(mid)) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}