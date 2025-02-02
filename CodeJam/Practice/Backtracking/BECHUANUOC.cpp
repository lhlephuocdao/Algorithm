#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k;
vector<int> h(12);
int ans = 0;

int maxWater(vector<int>& d)
{
    int res = 0;
    vector<int> a;
    for (int i = 0; i < n; i++)
        a.push_back(h[i] + d[i]);

    int l = 0, r = n-1;
    int maxl = a[l], maxr = a[r];
    while (l < r)
    {
        if (maxl < maxr) {
            maxl = max(maxl, a[l+1]);
            l++;
            res += maxl - a[l];
        } else {
            maxr = max(maxr, a[r-1]);
            r--;
            res += maxr - a[r];
        }
    }
    return res;
}

void calc(int pos, int k, vector<int>& delta, int sum)
{
    if (pos == n) {
        if (k == 0) {
            ans = max(ans, maxWater(delta));
        }
        return;
    }

    // Thử gán các giá trị từ 0 đến k cho phần tử a[idx]
    for (int i = 0; i <= k; i++) {
            delta[pos] = i;
            calc(pos+1, k-i, delta, sum + i);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i];
    vector<int> d(12);
    calc(0, k, d, 0);
    cout << ans << '\n';

    return 0;
}