#include <bits/stdc++.h>

using namespace std;

int solve (int n, int r) {
    int sum = 0;
    vector<int> p;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            p.push_back (i);
            while (n % i == 0) n /= i;
        }
    if (n > 1) p.push_back (n);
    /* p = [2, 3, 5] */
    for (int msk=1; msk<(1<<p.size()); ++msk) {
        /* msk: 1->7 */
        int mult = 1, bits = 0;
        for (int i=0; i<(int)p.size(); ++i)
        /* i: 0->2 */
        {
            if (msk & (1<<i)) {
                cout << "msk: " << msk << " i: " << i << '\n';
                ++bits;
                mult *= p[i];
                cout << "bits: " << bits << " mult: " << mult << '\n';
            }
        }
 
        int cur = r / mult;
        if (bits % 2 == 1) sum += cur;
        else sum -= cur;
        cout << "cur: " << cur << " sum: " << sum << '\n';
    }
    return r - sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << solve(60, 50) << '\n';

    return 0;
}