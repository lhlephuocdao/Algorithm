#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;

// directions: 0=up, 1=right, 2=down, 3=left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug :
 *      - duplicated element
 *      - consecutive range: 1 2 3 4 5 ....
 * stress test
 */

vector<pii> factorize(int n) {
    vector<pii> res;
    map<int, int> m;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            m[i]++;
            n /= i;
        }
    }
    if (n != 1) {
        m[n]++;
    }
    for (auto it : m) res.push_back({it.first, it.second});
    return res;
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<pii> f = factorize(n);
        int k = 0;
        int a = 0;
        for (auto x : f) {
            if (x.second > k) {
                k = x.second;
                a = x.first;
            }
        }
        cout << k << '\n';
        int p = 1;
        for (int i = 0; i < k-1; i++) {
            cout << a << ' ';
            p *= a;
        }
        cout << n/p << '\n';
    }
    return 0;
}