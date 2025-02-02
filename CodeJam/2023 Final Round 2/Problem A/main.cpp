#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long

int n,m;

struct my_data {
    ll tu = 0;
    ll mau = 0;
    double value = 0.0;
};

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) 
{ 
    return (a / gcd(a, b)) * b; 
}

void cong(my_data& d, ll tu, ll mau)
{
    if (tu == 0) return;
    ll t = gcd(tu, mau);
    tu = tu/t;
    mau = mau/t;

    if (d.tu == 0 && d.mau == 0) {
        d.tu = tu;
        d.mau = mau;
    } else {
        ll boi_chung = lcm(d.mau, mau);
        ll md = boi_chung/d.mau;
        ll mm = boi_chung/mau;

        d.tu = d.tu*md + tu*mm;
        d.mau = boi_chung;
    }

    ll tmp = gcd(d.tu, d.mau);
    d.tu /= tmp;
    d.mau /= tmp;
    d.value = (double)d.tu/(double)d.mau;
}

pair<ll, ll> sub(my_data& max, my_data& min)
{
    if (min.tu == 0) return make_pair(max.tu, max.mau);

    ll boi_chung = lcm(max.mau, min.mau);
    ll mmax = boi_chung/max.mau;
    ll mmin = boi_chung/min.mau;
    ll tu = max.tu*mmax - min.tu*mmin;
    ll mau = boi_chung;

    ll tmp = gcd(tu, mau);
    tu /= tmp;
    mau /= tmp;
    return make_pair(tu, mau);
}

void solve()
{
    cin >> n >> m;
    vector<my_data> sum;
    sum.resize(n);

    double max_value = -1.0, min_value = 100000.0;
    int i_max, i_min;

    while (m--)
    {
        ll v; cin >> v;
        for (int i = 0; i < n; i++)
        {
            ll a; cin >> a;
            /* add value */
            cong(sum[i], a, v);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
    	    if (max_value < sum[i].value) {
                max_value = sum[i].value;
                i_max = i;
            }
            if (min_value > sum[i].value) {
                min_value = sum[i].value;
                i_min = i;
            }
    }

    pair<ll, ll> ans = sub(sum[i_max], sum[i_min]);
    if (ans.second == 1) cout << ans.first << '\n';
    else cout << ans.first << "/" << ans.second << '\n'; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}