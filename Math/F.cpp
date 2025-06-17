#include <bits/stdc++.h>
#include <numeric>

using namespace std;
#define ll long long

ll gcd(ll A, ll B) {
    if (B == 0) return A;
    else return gcd(B, A % B);
}

ll lcm(ll a, ll b)
{
    return a/gcd(a, b) * b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> a;
    a.resize(n+1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll pre[100007];
    pre[n-1] = a[n];

    for (int i = n-2; i >= 1; i--)
        pre[i] = gcd(pre[i+1], a[i+1]);

    for (int i = 1; i < n; i++)
        pre[i] = lcm(a[i], pre[i]);

    ll ans = pre[1];
    for (int i = 2; i < n; i++)
        ans = gcd(ans, pre[i]);

    cout << ans << '\n';

    return 0;
}