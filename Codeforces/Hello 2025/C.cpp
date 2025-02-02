#include <bits/stdc++.h>
using namespace std;
#define int long long

int count_bits(int n)
{
    if (n == 0) return 1;
    int count = 0;
    while (n > 0) {
        count++;
        n >>= 1;
    }
    return count;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int l,r,a,b,c;
        cin >> l >> r;
        if (r-l == 2) {
            cout << l << " " << l+1 << " " << r << '\n';
            continue;
        }
        int cl = count_bits(l);
        int cr = count_bits(r);
        if (cl < cr) {
            a = 1 << (cr-1);
            b = a-1;
            if (b > l)
                c = l;
            else
                c = r;
        } else {
            int first_diff = count_bits(l^r) - 1;
            // cout << "first_diff: " << first_diff << '\n';
            int mask = ~((1<<first_diff)-1);
            a = r & mask;
            b = a-1;
            if (b > l)
                c = l;
            else
                c = r;
        }
        cout << a << " " << b << " " << c << '\n';
    }

    return 0;
}