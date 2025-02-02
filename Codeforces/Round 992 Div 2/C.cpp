#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> ans(n+1);
    if (n <= 40 && k > (1LL << (n-1))) {
        cout << -1 << '\n';
        return;
    } else {
        int l = 1, r = n, cur = 1;
        if (n <= 40) {
            int nums = (1LL << (n-1));
            while (cur <= n && l <= r) {
                if (k > nums/2) {
                    ans[r] = cur;
                    r--;
                    k -= nums/2;
                } else {
                    ans[l] = cur;
                    l++;
                }
                nums /= 2;
                cur++;
            }
        } else {
            int nums_39 = (1LL << 39); // 5,5 * 10^11
            int nums_40 = (1LL << 40); // 1,09 * 10^12
            while (cur <= n && l <= r) {
                // cout << "cur: " << cur << '\n';
                if (n-cur >= 40) {
                    ans[l] = cur;
                    l++;
                } else {
                    if (k > nums_39/2) {
                        ans[r] = cur;
                        r--;
                        k -= nums_39/2;
                    } else {
                        ans[l] = cur;
                        l++;
                    }
                    nums_39 /= 2;
                }
                cur++;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}