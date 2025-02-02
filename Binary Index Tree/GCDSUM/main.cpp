#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int maxN = 1e6 + 10;

int n,q, a[maxN], BIT[maxN];

int gcd(int A, int B) {
    if (B == 0) return A;
    else return gcd(B, A % B);
}

int F(int x)
{
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        ans += gcd(i, x);
        ans %= MOD;
    }
    return ans;
}

void update(int x, int val)
{
    for(; x <= maxN; x += x&-x)
        BIT[x] += val;
}

int query(int x)
{
    int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int val = F(a[i]);
            cout << "update: a[i]: " << a[i] << " and F(a[i]): " << val << '\n';
        update(a[i], val);
    }

    for (int i = 1; i <= 20; i++)
        cout << BIT[i] << " ";
    cout << '\n';

    cin >> q;
    while(q--)
    {
        char t;
        int x, y;
        cin >> t >> x >> y;
        if (t == 'U') {
            int val = -F(a[x]);
            update(a[x], F(y) - val);
            a[x] = y;
            // cout << "update: a[x]: " << a[x] << " and F(a[x]): " << val << '\n';
        } else {
            int q1 = query(a[y]);
            int q2 = query(a[x]);
            cout << "q1: " << q1 << " q2: " << q2 << '\n';
            int ans = q1 - q2;
            cout << ans << '\n';
        }
    }
    

    return 0;
}