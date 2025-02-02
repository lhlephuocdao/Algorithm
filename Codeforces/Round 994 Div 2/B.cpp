#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<pair<int, int>> a(n, {INT_MIN, INT_MAX}); // <min, max>
        int last_s = -1, last_p = -1, first_s = -1, first_p = -1;
        for (int i = 0; i < n; i++)
        {
            char x = s[i];
            if (x == 'p') { // [0, i] : length i+1
                last_p = i;
                if (first_p == -1) first_p = i;
                for (int j = 0; j <= i; j++) {
                    a[j].second = min(a[j].second, i);
                }
            } else if (x == 's') { // [i, n-1] : length n-i
                last_s = i;
                if (first_s == -1) first_s = i;
                for (int j = 0; j < n-i; j++) {
                    a[j].first = max(a[j].first, i);
                }
            }
        }

        bool check = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i].first > a[i].second) {
                check = false;
                break;
            }
        }

        // cout << "check: " << check << '\n';

        if (last_s != -1 && last_p != -1)
        {
            int common = first_p - last_s + 1;
            // cout << "first_p : " << first_p << " last_s: " << last_s << '\n';
            if (common < min(n-last_s, first_p+1))
                check = false;
        }

        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
}