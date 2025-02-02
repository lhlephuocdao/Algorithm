#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n,k;
unordered_map<string, vector<int>> m;

void solve()
{
    cin >> n >> k;
    m.clear();
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int n_upper = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] <= 'Z' && s[i] >= 'A') {
                n_upper++;
                s[i] = tolower(s[i]);
            }

        sort(s.begin(), s.end());
        m[s].push_back(n_upper);
    }

    ll ans = 0;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        vector<int> v = it->second;
        sort(v.begin(), v.end());
        int i = 0, size = v.size();
        int j = 0;
        while (i < size)
        {
            while (i < size -1 && v[i] == v[i+1]) i++;
            int count = i-j+1;
            ans += count*(count-1)/2;
            i++;
            j = i;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}