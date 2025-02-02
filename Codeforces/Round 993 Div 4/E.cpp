#include <bits/stdc++.h>
using namespace std;
#define int long long

long long fastPower(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        int min_v = l2/r1, max_v = r2/l1;
        if (l2 % r1 != 0) min_v += 1;

        int min_n, max_n;
        int n = 0, p = 1;
        while (p < min_v) {
            n++;
            p *= k;
        }
        min_n = n;

        while (p <= max_v) {
            n++;
            p *= k;
        }
        max_n = n-1;
        // cout << "min_n: " << min_n << " max_n: " << max_n << '\n';
        int ans = 0;
        for (int i = min_n; i <= max_n; i++) {
            int a = fastPower(k, i); // a = k^n
            int min_y = max(l2, a*l1);
            int max_y = min(a*r1, r2);
            // cout << "a: " << a << " min_y: " << min_y << " max_y: " << max_y << '\n';
            ans += max_y/a - min_y/a + 1;
            if (min_y%a != 0) ans -= 1;
        }
        cout << ans << '\n';
    }

    return 0;
}