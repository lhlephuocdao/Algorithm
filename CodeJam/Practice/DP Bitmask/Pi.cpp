#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k; cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    int q; cin >> q;
    while (q--)
    {
        int t,p;
        cin >> t >> p;

        int _max, _min;
        auto itr = upper_bound(a.begin(), a.end(), p);
        if (itr != a.end()) {
            _max = *itr;
            if (itr != a.begin()) _min = *(itr-1);
            else _min = INT_MIN;
        } else {
            _max = INT_MAX;
            if (k != 0) _min = a.back();
            else _min = INT_MIN;
        }

        _max = min(_max-1, p+t);
        _min = max(_min+1, p-t);

        int r_diff = _max - p;
        int l_diff = p - _min;
        int ans = 0;
        
        if (t%2 == 0) {
            ans = r_diff/2 + l_diff/2 + 1;
        } else {
            ans = (r_diff + 1)/2 + (l_diff+1)/2;
        }
        cout << ans << '\n';
    }

    return 0;
}