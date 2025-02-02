#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int sqr(int x) {
    return x*x;
}
 
int _pow(int a, int b) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(_pow(a, b/2)) % MOD;
        else
            return a * (sqr(_pow(a, b/2)) % MOD) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    vector<int> n(t), k(t);
    for (int i = 0; i < t; i++) cin >> n[i]; 
    for (int i = 0; i < t; i++) cin >> k[i];

    for (int i = 0; i < t; i++)
    {
        if (k[i] == 0 || k[i] == n[i]) {
            cout << 1 << '\n';
        } else {
            cout << _pow(2, k[i])%MOD << '\n';
        }
    }

    return 0;
}