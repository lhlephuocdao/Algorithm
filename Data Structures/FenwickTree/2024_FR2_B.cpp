#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

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

 class FenwickTree {
    private:
        int n;
        vector<int> bit1, bit2;

    public:
        FenwickTree(int n_) : n(n_) {
            bit1.assign(n+1, 0);
            bit2.assign(n+1, 0);
        }

        void update(vector<int>& bit, int u, int v) {
            int idx = u;
            while (idx <= n) {
                bit[idx] += v;
                idx += (idx & (-idx));
            }
        }

        void update(int l, int r, int val) {
            // bit1
            update(bit1, l, val);
            update(bit1, r+1, (-val+mod)%mod);

            // bit2
            update(bit2, l, val*(l-1)%mod);
            update(bit2, r+1, ((-val+mod)%mod)*r%mod);
        }

        int query(vector<int>& bit, int p) {
            int idx = p, ans = 0;
            while (idx > 0) {
                ans += bit[idx];
                ans %= mod;
                idx -= (idx & (-idx));
            }
            return ans;
        }

        int query(int k) {
            return ((query(bit1,k)*k%mod) - (query(bit2,k)%mod) + mod)%mod;
        }

        int rangeQuery(int l, int r) {
            return (query(r) - query(l-1) + mod)%mod;
        }
};

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        FenwickTree ft(n);
        vector<int> V(n+1), S(m+1), X(m+1), Y(m+1);
        for (int i = 1; i <= n; i++) {
            cin >> V[i];
            ft.update(i, i, V[i]);
        }

        for (int i = 1; i <= m; i++) cin >> S[i];
        for (int i = 1; i <= m; i++) cin >> X[i];
        for (int i = 1; i <= m; i++) cin >> Y[i];

        int origin = 1, flip = 0;
        // flip : 0 -> giu nguyen
        // flip : 1 -> doi chieu
        for (int i = 1; i <= m; i++)
        {
            if (S[i] == 1) {
                if (flip == 0) {
                    // rotate counterclockwise by X[i] -> origin increase
                    origin += X[i];
                    if (origin > n) origin = -n + origin;
                } else if (flip == 1) {
                    // rotate clockwise by X[i] -> origin decrease
                    origin -= X[i];
                    if (origin <= 0) origin = n+origin;
                }
            } else if (S[i] == 2) {
                if (flip == 0) {
                    // rotate clockwise by X[i] -> origin decrease
                    // origin = 2, rotate 3 cells - > expect origin = 5
                    origin -= X[i];
                    if (origin <= 0) origin = n+origin;
                } else if (flip == 1) {
                    // rotate counterclockwise by X[i] -> origin increase
                    origin += X[i];
                    if (origin > n) origin -= n;
                }
            } else if (S[i] == 3) {
                flip = (flip+1)%2;
            } else if (S[i] == 4) {
                //Increment the value in each of X[i] cells by Y[i] in clockwise order
                if (flip == 0) {
                    int l = origin, r = l + X[i] - 1;
                    if (r <= n) {
                        ft.update(l, r, Y[i]);
                    } else {
                        int l1 = l, r1 = n, l2 = 1, r2 = r-n;
                        ft.update(l1, r1, Y[i]);
                        ft.update(l2, r2, Y[i]);
                    }
                } else if (flip == 1) {
                    //Increment the value in each of X[i] cells by Y[i] in counterclockwise order
                    int r = origin, l = origin-X[i]+1;
                    if (l >= 1) {
                        ft.update(l, r, Y[i]);
                    } else {
                        int r1 = r, l1 = 1, r2 = n, l2 = n+l;
                        ft.update(l1, r1, Y[i]);
                        ft.update(l2, r2, Y[i]);
                    }
                }
            } else if (S[i] == 5) {
                //Compute the sum of the values in X[i] cells starting from the origin cell in clockwise order
                if (flip == 0) {
                    int l = origin, r = l + X[i] - 1;
                    if (r <= n) {
                        int ans = ft.rangeQuery(l, r);
                        cout << ans%mod << " ";
                    } else {
                        int l1 = l, r1 = n, l2 = 1, r2 = r-n;
                        int ans = ft.rangeQuery(l1, r1) + ft.rangeQuery(l2, r2);
                        cout << ans%mod << " ";
                    }
                } else if (flip == 1) {
                    int r = origin, l = origin-X[i]+1;
                    int ans = 0;
                    if (l >= 1) {
                        ans = ft.rangeQuery(l, r);
                    } else {
                        int r1 = r, l1 = 1, r2 = n, l2 = n+l;
                        ans = ft.rangeQuery(l1, r1) + ft.rangeQuery(l2, r2);
                    }
                    cout << ans%mod << " ";
                }
            }
        }
        cout << '\n';
    }
    return 0;
}