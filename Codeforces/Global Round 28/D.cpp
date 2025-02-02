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
        int n,m;
        cin >> n >> m;
        vector<int> a(n-1), b(m);
        int kevin_val; cin >> kevin_val;
        for (int i = 0; i < n-1; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
        vector<int> kevin_solve, kevin_not_solve;
        for (auto x : b)
            if (x <= kevin_val) kevin_solve.push_back(x);
            else kevin_not_solve.push_back(x);

        int kevin_size = kevin_solve.size();
        int kevin_not_size = m - kevin_size;

        vector<int> count(kevin_not_size, 0);
        int i = 0;
        for (int j = 0; j < kevin_not_size; ++j) {
            while (i < a.size() && a[i] < kevin_not_solve[j]) {
                ++i;
            }
            count[j] = a.size()-i;
        }

        for (int k = 1; k <= m; k++)
        {
            int ans = 0;
            int num_contest = m/k;
            int rank1 = kevin_size/k;
            ans += rank1;
            num_contest -= rank1;

            int diff_kevin = 0;
            if (kevin_size%k != 0) diff_kevin = k - kevin_size%k;
            int p = kevin_not_size-diff_kevin;
            if (diff_kevin > 0 && p >= 0) {
                ans += count[p] + 1;
                num_contest--;
                p -= k;
            } else {
                p = kevin_not_size-1 - k + 1;
            }

            while (p >= 0 && num_contest > 0) {
                ans += count[p] + 1;
                p -= k;
                num_contest--;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }

    return 0;
}