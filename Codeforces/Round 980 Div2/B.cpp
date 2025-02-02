#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        mp[p]++;
    }

    for (auto itr : mp)
        a.push_back({itr.first, itr.second});
    sort(a.begin(), a.end());

    int ans = 0, sum = 0, min = 0, used = 0;
    for (int i = 0; i < a.size(); i++) {
        int need = k - sum;
        min = a[i].first;
        int m = n-used;

        if ((need-1)/m >= min) {
            sum += min * a[i].second;
            ans += (min + 1) * a[i].second;
            used += a[i].second;
        } else {
            ans += need;
            break;
        }
    }

    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}