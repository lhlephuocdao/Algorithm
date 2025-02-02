#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,x;
    cin >> n >> x;
    vector<long long> pre(n+1);
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        pre[i] = pre[i-1] + a;
    }

    int ans = 0;
    map<long long, int> m;
    for (int i = 0; i < n+1; i++)
    {
        long long v = pre[i];
        ans += m[v-x];
        m[v]++;
    }
    cout << ans << '\n';
    return 0;
}