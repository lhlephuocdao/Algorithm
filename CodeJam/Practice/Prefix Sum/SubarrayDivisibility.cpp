#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) cin >> a[i];

    map<int, int> pre;
    pre[0]++;
    int prefix = 0;
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        int x = a[i];
        x %= N;
        if (x < 0) x += N;
        prefix += x;
        prefix %= N;
        if (prefix < 0) prefix += N;
        ans += pre[prefix];
        pre[prefix]++;
    }

    cout << ans << '\n';

    return 0;
}