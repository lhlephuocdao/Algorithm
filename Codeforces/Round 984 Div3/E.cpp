#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll_max LONG_LONG_MAX
#define ll_min LONG_LONG_MIN

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,k,q;
    cin >> n >> k >> q;
    vector<vector<int>> a(n, vector<int>(k));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
            if (i>0) a[i][j] |= a[i-1][j];
        }
    }

    vector<vector<int>> b(k, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            b[j][i] = a[i][j];

    while (q--)
    {
        int m; cin >> m;
        int left_idx = 0, right_idx = n-1; // min index, max index
        
        while(m--)
        {
            int r,c; char o;
            cin >> r >> o >> c;
            r--;
            if (o == '<') {
                int left = 0, right = n-1, mid, imax = -1;
                while (left <= right) {
                    mid = (left+right)/2;
                    if (b[r][mid] < c) {
                        imax = mid;
                        left = mid+1;
                    } else {
                        right = mid-1;
                    }
                }
                right_idx = min(right_idx, imax);
            } else {
                int left = 0, right = n-1, mid, imin = n;
                while (left <= right) {
                    mid = (left+right)/2;
                    if (b[r][mid] > c) {
                        imin = mid;
                        right = mid-1;
                    } else {
                        left = mid+1;
                    }
                }
                left_idx = max(left_idx, imin);
            }
        }
        if (left_idx <= right_idx) cout << (left_idx+1) << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}