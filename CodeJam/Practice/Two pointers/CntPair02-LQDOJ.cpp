#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,x;
    cin >> n >> x;
    vector<pair<int, int>> a;
    int pre = -1, count = 1;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t == pre) count++;
        else {
            if (pre != -1) a.push_back({pre, count});
            pre = t;
            count = 1;
        }
    }
    a.push_back({pre, count});

    int size = a.size();
    int l = 0, r = size-1;
    long long ans = 0;
    while (l<=r)
    {   if (2 * a[l].first != x && 2*a[r].first != x) {
            int sum = a[l].first + a[r].first;
            if (sum == x) {
                ans += (long long)a[l].second * (long long)a[r].second;
                l++; r--;
            } else if (sum < x) l++;
            else r--;
        } else if (2 * a[l].first == x ) {
            long long k = a[l].second;
            ans += k*(k-1)/2;
            break;
        } else if (2 * a[r].first == x) {
            long long k = a[r].second;
            ans += k*(k-1)/2;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}