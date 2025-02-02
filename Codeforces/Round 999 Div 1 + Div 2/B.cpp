#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug
 * stress test
 */

int32_t main()
{
    fastio;

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        map<int, int> cnt;
        for (auto& x : a) {
            cin >> x;
            cnt[x]++;
        }

        vector<int> candidates;
        bool check = false;
        for (auto itr : cnt) {
            int key = itr.first, value = itr.second;
            // cout << "key: " << key << " value: " << value << '\n';
            if (value >= 4) {
                cout << key << " " << key << " " << key << " " << key << '\n';
                check = true;
                break;
            }

            if (value >= 2) {
                candidates.push_back(key);
                cnt[key] -= 2;
            }
        }

        if (check) continue;

        vector<int> v;
        for (auto itr : cnt) if (itr.second > 0) v.push_back(itr.first);

        // for (auto c : v) cout << c << " ";
        // cout << '\n';

        if (candidates.size() == 0)
            cout << -1 << '\n';
        else if (candidates.size() >= 2) {
            int x = candidates[0];
            int y = candidates[1];
            cout << x << " " << x << " " << y << " " << y << '\n';
        }
        else {
            int x = candidates[0];
            int sz = v.size();
            int idx = 0;
            while (idx+1 < sz && 2*x <= (v[idx+1] - v[idx])) idx++;
            if (idx < sz-1)
                cout << x << " " << x << " " << v[idx] << " " << v[idx+1] << '\n';
            else
                cout << -1 << '\n';
        }

    }
    return 0;
}