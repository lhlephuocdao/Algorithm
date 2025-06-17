#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> sub_gcd[n];
    /*
        Key is gcd,
        Value is the largest length such that gcd(a[i - len], ..., a[i]) equals to key.
    */
    sub_gcd[0][a[0]] = 1;
    for(int i = 1; i < n; i++)
    {
        sub_gcd[i][a[i]] = 1;
        for(auto it: sub_gcd[i - 1])
        {
            int new_gcd = __gcd(it.first, a[i]);
            sub_gcd[i][new_gcd] = max(sub_gcd[i][new_gcd], it.second+1);
        }
    }

    int ans[n+1]; // ans[i] : max gcd of a subarray of size i
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++)
        for (auto it : sub_gcd[i])
            ans[it.second] = max(ans[it.second], it.first);

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}