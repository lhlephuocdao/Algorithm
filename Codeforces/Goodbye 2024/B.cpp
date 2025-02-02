#include <bits/stdc++.h>
using namespace std;
#define int long long

void log(vector<int>& a) {
    for (auto x : a) cout << x << ' ';
    cout << '\n';
}

const int MAX = 2e5 + 1;
int A[MAX], N;
 
void update(int BIT[], int u, int v)
{
    int i = u;
    while (i <= N+10)
    {
        BIT[i] += v;
        i += (i & (-i));
    }
}
 
int getSum(int BIT[], int p)
{
    int ans = 0;
    while (p > 0)
    {
        ans += BIT[p];
        p -= (p & (-p));
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        N = n;
        vector<pair<int, int>> a(n);
        map<int, int> c;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            if (a[i].first == a[i].second) {
                c[a[i].first]++;
            }
        }

        vector<int> pre(2*n + 1, 0);
        for (int i = 1; i < 2*n+1; i++) {
            pre[i] = pre[i-1] + (c[i] > 0 ? 1 : 0);
        }

        string s;
        for (int i = 0; i < n; i++) {
            int l = a[i].first;
            int r = a[i].second;
            if (l == r) {
                if (c[l] == 1) {
                    s += '1';
                } else {
                    s += '0';
                }
                continue;
            }

            int count = pre[r] - pre[l-1];
            if (count == r-l+1)
                s += '0';
            else
                s += '1';
        }
        cout << s << '\n';
    }

    return 0;
}