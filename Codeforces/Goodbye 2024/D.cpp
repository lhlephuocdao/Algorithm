#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;

long long Pow(long long a, long long b) {
    long long ans = 1;
    while (b > 0){
        if (b % 2) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n,q;
        cin >> n >> q;
        vector<int> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        vector<int> aa = a, bb = b;
        sort(aa.begin(), aa.end());
        sort(bb.begin(), bb.end());
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans *= min(aa[i], bb[i]);
            ans %= mod;
        }
        cout << ans << ' ';
        while (q--) {
            int type,x;
            cin >> type >> x;
            x--;
            if (type == 1) {
                int id = upper_bound(aa.begin(), aa.end(), a[x]) - aa.begin() - 1;
                if (aa[id] < bb[id])
                    ans = (ans * Pow(aa[id], mod-2) % mod) * (aa[id] + 1) % mod;
                a[x]++;
                aa[id]++;
            } else {
                int id = upper_bound(bb.begin(), bb.end(), b[x]) - bb.begin() - 1;
                if (bb[id] < aa[id])
                    ans = (ans * Pow(bb[id], mod-2) % mod) * (bb[id] + 1) % mod;
                b[x]++;
                bb[id]++;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }

    return 0;
}