#include <bits/stdc++.h>

using namespace std;

const int inf  = 1e9 + 7;
const int maxN = 5e4 + 7;
int n, m;
int a[maxN], pref[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    a[0] = 0;
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = a[i] + pref[i-1];
    }

    cin >> m;
    while (m--) {
        int x, y, s = 0, m = -inf;
        cin >> x >> y;
        for (int i = x; i <= y; i++)
        {
            s += a[i];
            if (s > m) m = s;
            if (s < 0) s = 0;
        }

        cout << m << '\n';
    }

    return 0;
}