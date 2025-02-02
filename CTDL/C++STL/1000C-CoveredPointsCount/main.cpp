#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 2e5 + 7;
int n;
ll mark[2*maxn], pre[2*maxn];
map<int, ll> mp;
map<int, ll> ans;
vector<ll> v;

struct point {
    ll l;
    ll r;
} p[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll l, r;
        cin >> l >> r;
        p[i].l = l;
        p[i].r = r;
        v.push_back(l);
        v.push_back(r+1);
    }

    // v[] : 0  1   3   4   9
    // size =  5

    sort(v.begin(), v.end());
    vector<ll>::iterator ip = unique(v.begin(), v.end());
    int size = distance(v.begin(), ip);

    for (int i = 1; i <= n; i++)
    {
        int new_l = distance(v.begin(), lower_bound(v.begin(), v.begin() + size, p[i].l));
        int new_r = distance(v.begin(), lower_bound(v.begin(), v.begin() + size, p[i].r+1));
        mark[new_l]++;
        mark[new_r]--;
    }

    pre[0] = mark[0];
    for (int i = 1; i < size; i++)
        pre[i] = pre[i-1] + mark[i];

    for (int i = 0; i < size; i++) {
        ll tmp = (i != size-1) ? v[i+1] - v[i] : 1;
        ans[pre[i]] += tmp;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    return 0;
}