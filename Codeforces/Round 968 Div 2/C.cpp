#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> m;
        for (int i = 0; i < n; i++)
            m[s[i]]++;

        vector<pair<char, int>> a;
        for (auto itr : m) a.push_back({itr.first, itr.second});
        sort(a.begin(), a.end(), [&](pair<char, int>& x, pair<char, int>& y){
            return x.second < y.second;
        });

        vector<char> v(n);
        int idx = 0;
        for (auto itr = a.rbegin(); itr != a.rend(); itr++)
        {
            char c = itr->first;
            int cnt = itr->second;
            for (int i = 0; i < cnt; i++)
            {
                v[idx] = c;
                idx += 2;
                if (idx >= n) idx = 1;
            }
        }
        string ans;
        for (auto x : v) ans += x;
        cout << ans << '\n';
    }
    return 0;
}