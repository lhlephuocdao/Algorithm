#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
long long sum, ans;

/*
4 2
5 5 5 9
*/

void backtrack(int pos, ll sum, ll prev, vector<int>& a)
{
    if (pos == n-1) {
        sum += prev;
        sum = (sum + m) % m;
        if (sum == 0) {
            ans++;
        }
        return;
    }

    for (int sign = 0; sign < 3; sign++)
    {
        ll t_s = sum, t_p = prev;
        if (sign == 0) {
            t_s += prev;
            t_p = a[pos+1];
        } else if (sign == 1) {
            t_s += prev;
            t_p = -a[pos+1];
        } else {
            t_p *= a[pos+1];
        }

        t_s = (t_s + m)%m;
        t_p = (t_p + m)%m;

        backtrack(pos+1, t_s, t_p, a);
    }
}

void solve()
{
    sum = 0, ans = 0;
    vector<int> a(20, 0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    backtrack(0, sum, (ll)a[0], a);
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
