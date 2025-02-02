#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        vector<int> suffix(n);
        suffix[n-1] = (s[n-1] == '1' ? 1 : -1);
        for (int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] + (s[i] == '1' ? 1 : -1);
        }

        priority_queue<int> pq;
        for (int i = 1; i < n; i++)
            pq.push(suffix[i]);

        int sum = 0, ans = 2;
        bool check = false;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();

            if (sum >= k) {
                cout << ans << '\n';
                check = true;
                break;
            }
            ans++;
        }
        if (!check) cout << -1 << '\n';
    }

    return 0;
}