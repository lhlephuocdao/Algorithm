#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n; cin >> n;
    vector<int> ans;
    int max_k = 0;

    if (n&1) {
        max_k = n;
        ans.push_back(n);
        ans.push_back(n-1);
        ans.push_back(1);
        ans.push_back(3);
        for (int i = 2; i < n-1; i++)
            if (i != 3) ans.push_back(i);
    } else {
        int x = static_cast<int>(log2(n)) + 1;
        int maxMask = (1<<x) - 1;
        max_k = maxMask;
        vector<bool> used(n+1, false);
        ans.push_back(n);
        used[n] = true;
        int a = maxMask ^ n;
        ans.push_back(a);
        used[a] = true;

        int count = 0, p = a;
        while (p % 2 == 1) {
            count++;
            p /= 2;
        }

        int t = a + (1<<count);
        if (t < n) {
            ans.push_back(t);
            used[t] = true;
        } else {
            ans.push_back(a-1);
            ans.push_back(1);
            ans.push_back(3);
            used[a-1] = used[1] = used[3] = true;
        }

        for (int i = 1; i < n; i++)
            if (used[i] == false)
                ans.push_back(i);
    }

    reverse(ans.begin(), ans.end());
    cout << max_k << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}