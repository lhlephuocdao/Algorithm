#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e5 + 7;
int n,q;
ll a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while(q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            int val;
            cin >> val;
            for (int i = l; i <= r; i++)
                a[i] += val;
        } else {
            long long ans = 0;
            for (int i = l; i <= r; i++)
                ans += a[i];

            cout << ans << '\n';
        }
    }

    return 0;
}