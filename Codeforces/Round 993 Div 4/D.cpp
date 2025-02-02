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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<bool> check(n+1, false);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            check[a[i]] = true;
        }

        vector<int> tmp, ans;
        for (int i = 1; i <= n; i++)
            if (check[i] == false)
                tmp.push_back(i);

        vector<bool> used(n+1, false);
        int idx_t = 0;
        for (int i = 0; i < n; i++)
        {
            if (used[a[i]] == false) {
                ans.push_back(a[i]);
                used[a[i]] = true;
            } else {
                assert(idx_t < tmp.size());
                ans.push_back(tmp[idx_t]);
                idx_t++;
            }
        }
        for (auto x : ans) cout << x << " ";
        cout << '\n';
    }

    return 0;
}