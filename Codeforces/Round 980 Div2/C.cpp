#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), [&](pair<int, int>& a, pair<int, int>&b){
        int suma = a.first + a.second;
        int sumb = b.first + b.second;
        return suma < sumb;
    });
    for (int i = 0; i < n; i++)
        cout << a[i].first << " " << a[i].second << " ";
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}