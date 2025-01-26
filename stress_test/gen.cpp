#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define ll long long

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b)
{
    if (a > b) return 0;
    return a + rng() % (b - a + 1);
}

int main()
{
    fastio;

    ll n = random(1, 50);
    cout << n << '\n';

    for (ll i = 0; i < n; i++)
        cout << random(0, 101) << ' ';

    return 0;
}