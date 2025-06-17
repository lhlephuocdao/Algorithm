#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    bitset<3007> a[3007];
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
        {
            int count = (a[i]&a[j]).count();
            ans += (1ll*count*(count-1))/2;
        }

    cout << ans << '\n';

    return 0;
}