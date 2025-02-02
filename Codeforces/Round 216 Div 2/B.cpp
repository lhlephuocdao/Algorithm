#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,k,l,r,Sa,Sk;
    cin >> n >> k >> l >> r >> Sa >> Sk;    

    int min_a = Sk/k;
    int du_sk = Sk % k;
    int min_remain = (k != n) ? (Sa - Sk)/(n-k) : 0;
    int du_remain = (k!=n) ? (Sa - Sk)%(n-k) : 0;
    vector<int> a(n);
    for (int i = 0; i < k; i++) {
        a[i] = min_a;
        if (du_sk > 0) {
            a[i]++;
            du_sk--;
        }
    }

    for (int i = k; i < n; i++) {
        a[i] = min_remain;
        if (du_remain > 0) {
            a[i]++;
            du_remain--;
        }
    }

    for (auto x : a) cout << x << " ";

    return 0;
}