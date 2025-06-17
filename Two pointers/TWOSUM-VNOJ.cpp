#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& pre, int start, int end, int target)
{
    int lo = start, hi = end;
    while (lo <= hi)
    {
        int mid = lo + (hi-lo)/2;
        if (pre[mid] == target)
            return mid;
        else if (pre[mid] < target)
            lo = mid+1;
        else
            hi = mid-1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n+1), pre(n+1);
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            int sum = pre[j] - pre[i-1];
            if (sum%2 == 1) continue;

            int target = pre[i-1] + sum/2;
            if (search(pre, i, j, target) != -1)
                ans = max(ans, j-i+1);
        }
    }

    cout << ans << '\n';

    return 0;
}