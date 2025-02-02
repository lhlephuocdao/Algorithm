#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> tmp;
    
    int id = 0;
    while(k>0)
    {
        ll t = (ll)(1<<id);
        if (k >= t) {
            tmp.push_back(t);
            k -= t;
        } else {
            tmp.push_back(k);
            k = 0;
        }
        id++;
    }

    vector<ll> ans(n,0);
    int i = n-1;
    int j = tmp.size()-1;

    while(i >=0 && j >= 0)
    {
        ans[i] = tmp[j];
        i--;
        j--;
    }

    if (j >= 0) 
        for (int x = 0; x <= j; x++)
            ans[0] += tmp[x];

    for (int x = 0; x < n; x++)
        cout << ans[x] << " ";
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}