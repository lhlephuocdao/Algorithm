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

    int t = 1;
    while (t--)
    {
        const int maxa = 1e6 + 1;
        vector<int> cnt(maxa, 0);
        for (int i = 2; i < maxa; i++)
            if (cnt[i] == 0) {
                for (int j = 2*i; j < maxa; j += i)
                    cnt[j]++;
            }

        vector<int> x;
        for (int i = 2; i < maxa; i++)
            if (cnt[i] == 2) x.push_back(i*i);

        int q;
        cin >> q;
        while (q--)
        {
            int a; cin >> a;
            auto itr = upper_bound(x.begin(), x.end(), a);
            itr--;
            cout << *itr << '\n';
        }
    }
    return 0;
}