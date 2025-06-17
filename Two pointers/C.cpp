#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n-2; i++)
    {
        int x = a[i].first;
        int l = i+1, r = n-1;
        while (l < r)
        {
            int y = a[l].first;
            int z = a[r].first;
            int t = x+y+z;
            if (t == d) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << '\n';
                return 0;
            } else if (t > d) r--;
            else l++;
        }
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}