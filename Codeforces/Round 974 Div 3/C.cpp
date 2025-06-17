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
        int n; cin >> n;
        vector<int> a(n);
        double total = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
        }

        sort(a.begin(), a.end());

        if (n==1 || n==2) {
            cout << -1 << '\n';
            continue;
        }

        double epsilon = 1e-6;
        function<bool(double, double)> less = [&epsilon](double a, double b){
            if (fabs(a - b) < epsilon) return false;
            return a < b;
        };

        function<bool(double)> check = [&](double half){
            int cnt = 0;
            for (int i = 0; i < n-1; i++)
            {
                double x = (double)a[i];
                if (less(x, half)) cnt++;
            }
            return cnt > n/2;
        };

        double k = (double)total/n;
        k = k/2;
        if (check(k)) {
            cout << 0 << '\n';
            continue;
        }

        int start = 1, end = 1e18;
        int ans = 1e18;
        while (start <= end) {
            int mid = (start + end)/2;
            double new_total = total + (double)mid;
            double average = (double)new_total/n;
            double h = average/2;
            // cout << "start: " << start << " end: " << end << '\n';
            // cout <<"mid: " << mid << " half: " << h << '\n';
            if (check(h)) {
                ans = min(mid, ans);
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        if (ans == 1e18)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}