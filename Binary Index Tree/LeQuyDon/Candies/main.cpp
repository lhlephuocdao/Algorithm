#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+7;
int n,m, a[maxn];
int BIT[maxn];

void update(int x, int val)
{
    while (x <= n) {
        BIT[x] += val;
        x += x & (-x);
    }
}

int get(int x)
{
    int ans = 0;
    while (x > 0) {
        ans += BIT[x];
        x -= x & (-x);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1);
    for (int i = 1; i<=n; i++) {
        update(i, a[i]);
        update(i+1, -a[i]);
    }

    cin >> m;
    while(m--) {
        int t; cin >> t;
        int l = 1, r = n, ans = -1;
        while (l <= r)
        {
            int mid = (l+r)/2;
            if (get(mid) >= t) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (ans != -1) {
            cout << (n-ans+1) << '\n';
            //Subtract -1 from [ans, n]
            update(ans, -1);
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}