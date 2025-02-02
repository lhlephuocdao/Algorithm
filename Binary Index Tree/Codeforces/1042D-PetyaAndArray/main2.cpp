#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 2e5 + 7;
int n, BIT[maxn];
ll t, pre[maxn], b[maxn];

void update(int ind, int val)
{
    while (ind <= n+1)
    {
        BIT[ind] += val;
        ind += ind & (-ind);
    }
}

int get(int idx)
{
    int ans = 0;
    while (idx > 0)
    {
        ans += BIT[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> t;
    
    int x;
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        pre[i] = x + pre[i-1];
        b[i] = pre[i]; 
    }

    sort(b+1, b+n+1);
    int size = unique(b+1, b+n+1)-b-1;

    ll ans = 0;
    for (int i = n ; i > 0; i--)
    {
        int pos = lower_bound(b+1, b+size+1, pre[i])-b;
        update(pos, 1);
        ans += get(upper_bound(b+1, b+size+1, pre[i-1]+t-1) -b -1);
    }

    cout << ans ;

    return 0;
}