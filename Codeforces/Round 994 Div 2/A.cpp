#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        int count = 0;
        int i = 0;
        while (i < n) {
            while (i<n && a[i] == 0) i++;
            if (i>=n) break;
            while (i<n && a[i] != 0) i++;
            count++;
        }
        count = min(count, 2);
        cout << count << '\n';
    }
}