#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct point {
    ll start;
    ll end;
    ll count;
};

ll a, b, c;
map<ll, point> m;

void solve()
{
    cin >> a >> b >> c;
    ll aa = 1, bb = 0;
    m.clear();
    for (ll j = 0; j <= 16; j++)
    {
        if (j > 0) aa *= 10;
        bb *= 1ll*10;
        bb += 9;

        ll min_i = (b - a + aa)/b;
        if ((b - a + aa) % b != 0) min_i++;
        if (min_i <= 1) min_i = 1;
        ll max_i = (b - a + bb)/b;

        if (max_i < 1) continue;

        point p = {min_i, max_i, max_i - min_i + 1};
        m[j+1] = p;
    }

    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        ll num = itr->first;
        point p = itr->second;
        ll count = p.count;
        if (c > 1ll*num*count) {
            c -= 1ll*num*count;
        } else {
            ll nguyen = c/num;
            ll du = c % num;
            ll tt = 0;

            if (du == 0) tt = nguyen;
            else tt = nguyen + 1;

            tt = tt + p.start - 1;

            ll target = a + b*(tt-1);
            string str = to_string(target);

            if (du == 0) cout << str[num-1] << '\n';
            else cout << str[du-1] << '\n';

            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}