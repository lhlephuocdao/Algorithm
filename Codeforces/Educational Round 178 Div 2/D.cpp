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

int32_t main()
{
    fastio;

    const int max_n = 1e7;
    vector<bool> is_prime(max_n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= max_n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_n; j += i)
            is_prime[j] = false;
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= max_n; i++)
        if (is_prime[i]) primes.push_back(i);

    int sz = primes.size();
    vector<int> pre(sz);
    pre[0] = primes[0];
    for (int i = 1; i < sz; i++)
        pre[i] = pre[i-1] + primes[i];

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (auto& x : a) cin >> x, sum += x;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto x : a) pq.push(x);
        int max_sum = pre[n-1];

        if (sum >= max_sum) {
            cout << 0 << '\n';
        } else {
            int ans = 0;
            while (sum < pre[pq.size()-1]) {
                sum -= pq.top();
                pq.pop();
                ans++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}