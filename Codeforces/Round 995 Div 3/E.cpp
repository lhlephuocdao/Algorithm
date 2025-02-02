#include <bits/stdc++.h>
using namespace std;
#define int long long

void log(vector<int>& a) {
    for (auto x : a) cout << x << ' ';
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n), V;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            V.push_back(a[i]);
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            V.push_back(b[i]);
        }

        sort(V.begin(), V.end());
        auto itr = unique(V.begin(), V.end());
        V.resize(distance(V.begin(), itr));
        // log(V);
        int sz = V.size();
        // cout << "sz: " << sz << '\n';

        vector<int> ne(sz+2, 0), c(sz+2, n), mark(sz+2, 0), mark2(sz+2, 0);
        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
            b[i] = lower_bound(V.begin(), V.end(), b[i]) - V.begin() + 1;
            mark[a[i]+1]++;
            mark[b[i]+1]--;
            mark2[b[i]+1]++;
        }

        for (int i = 1; i < sz + 2; i++) {
            ne[i] = ne[i-1] + mark[i];
            c[i] = c[i-1] - mark2[i];
        }

        // log(a);
        // log(b);
        // log(mark);
        // log(mark2);
        // log(ne);
        // log(c);

        int ans = 0;
        for (int i = 1; i < sz+1; i++) {
            if (ne[i] <= k) {
                int val = V[i-1];
                ans = max(ans, val*c[i]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}