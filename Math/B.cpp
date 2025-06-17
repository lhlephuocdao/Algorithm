#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    ll m = 1;
    for (int i = 1; i < n; i++)
    {
        /* if gcd(a,m) = 1 -> tồn tại x sao cho a*x = 1 (mod m) */
        if (__gcd(i, n) == 1) {
            v.push_back(i);
            m *= i;
            m %= n;
        }
    }

    if (m != 1) {
        cout << v.size() - 1 << '\n';
        for (auto x : v)
            if (x != m) cout << x << " ";
    } else {
        cout << v.size() << '\n';
        for (auto x : v) cout << x << ' ';
    }

    return 0;
}