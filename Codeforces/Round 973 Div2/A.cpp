#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        cout << n/(min(x, y)) + (n%min(x,y) == 0 ? 0 : 1) << '\n';
    }

    return 0;
}