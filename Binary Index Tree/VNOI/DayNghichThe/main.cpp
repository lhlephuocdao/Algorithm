#include <bits/stdc++.h>

using namespace std;

const int maxn = 6e4 + 1;
int n, a[maxn], BIT[maxn];

void update(int id, int val)
{
    while (id <= maxn)
    {
        BIT[id] += val;
        id += id & (-id);
    }
}

int get(int id)
{
    int ans = 0;
    while (id > 0)
    {
        ans += BIT[id];
        id -= id & (-id);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        int x = a[i];
        ans += get(x-1);
        update(x, 1);
    }
    cout << ans << '\n';

    return 0;
}