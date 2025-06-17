#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,k; cin >> n >> k;
    int x[n];
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    long long m = sum/k;
    if (sum % k != 0) m++;

    cout << "sum: " << sum << '\n';
    cout << "m: " << m << '\n';

    long long diff = LONG_MAX, total = 0, max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total += x[i];
        if (abs(total - m) <= diff) {
            diff = abs(total - m);
        } else {
            diff = LONG_MAX;
            max_sum = std::max(max_sum, total-x[i]);
            cout << "i: " << i << " x: " << x[i] << " max: " << max_sum << '\n';
            total = x[i];
            diff = std::min(diff, abs(total-m));
        }
    }

    cout << "total: " << total << '\n';

    max_sum = std::max(max_sum, total);

    cout << max_sum << '\n';

    return 0;
}