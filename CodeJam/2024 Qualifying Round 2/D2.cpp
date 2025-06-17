#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int INF = 1e18;

// directions: 0=up, 1=right, 2=down, 3=left
// 4=up-left, 5=down-right, 6=up-right, 7=down-left
int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

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

struct DSU {
    vector<int> parent, sz;

    DSU(int n) : parent(n), sz(n) {};

    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }

    int find_set(int v) {
        return v == parent[v] ? v : parent[v] = find_set(parent[v]);
    }

    int find_size(int v) {
        int root = find_set(v);
        return sz[root];
    }

    void join_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

int32_t main()
{
    fastio;

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        /*=========================TREE - A - ==============================*/
        int NA, MA;
        cin >> NA >> MA;
        vector<bool> specialA(NA+1, false);
        vector<int> SA;
        for (int i = 0; i < MA; i++) {
            int x; cin >> x;
            specialA[x] = true;
            SA.push_back(x);
        }

        vector<vector<int>> treeA(NA+1);

        DSU DSU_A(NA+1);
        for (int i = 1; i <= NA; i++) DSU_A.make_set(i);

        for (int i = 0; i < NA-1; i++) {
            int u,v; cin >> u >> v;
            treeA[u].push_back(v);
            treeA[v].push_back(u);
            if (!specialA[u] && !specialA[v]) {
                DSU_A.join_sets(u, v);
            }
        }

        vector<int> X(NA+1, -1);
        for (auto u : SA) {
            assert(specialA[u]);
            int total = 0;
            for (auto v : treeA[u]) {
                // Xét các node non-special xung quanh node u special
                if (!specialA[v])
                    total += DSU_A.find_size(v);
            }
            X[u] = total + 1;
        }

        for (int i = 1; i <= NA; i++) {
            if (!specialA[i]) {
                int root = DSU_A.find_set(i);
                int sz = DSU_A.find_size(root);
                if (X[root] == -1) X[root] = 0;
                for (auto v : treeA[i]) {
                    if (specialA[v]) {
                        X[root] += X[v] - sz;
                    }
                }
            }
        }

        for (int i = 1; i <= NA; i++)
            if (!specialA[i]) {
                int root = DSU_A.find_set(i);
                X[i] = X[root];
            }

        int sumX = 0, SX = 0;
        for (int i = 1; i <= NA; i++) {
            sumX = (sumX + X[i])%mod;
            SX = (SX + i*X[i]%mod)%mod;
        }
        /*=========================TREE - A - ==============================*/

        /*=========================TREE - B - ==============================*/
        int NB, MB;
        cin >> NB >> MB;
        vector<bool> specialB(NB+1, false);
        vector<int> SB;
        for (int i = 0; i < MB; i++) {
            int x; cin >> x;
            specialB[x] = true;
            SB.push_back(x);
        }

        vector<vector<int>> treeB(NB+1);

        DSU DSU_B(NB+1);
        for (int i = 1; i <= NB; i++) DSU_B.make_set(i);

        for (int i = 0; i < NB-1; i++) {
            int u,v; cin >> u >> v;
            treeB[u].push_back(v);
            treeB[v].push_back(u);
            if (!specialB[u] && !specialB[v]) {
                DSU_B.join_sets(u, v);
            }
        }

        vector<int> Y(NB+1, -1);
        for (auto u : SB) {
            assert(specialB[u]);
            int total = 0;
            for (auto v : treeB[u]) {
                // Xét các node non-special xung quanh node u special
                if (!specialB[v])
                    total += DSU_B.find_size(v);
            }
            Y[u] = total + 1;
        }

        for (int i = 1; i <= NB; i++) {
            if (!specialB[i]) {
                int root = DSU_B.find_set(i);
                int sz = DSU_B.find_size(root);
                if (Y[root] == -1) Y[root] = 0;
                for (auto v : treeB[i]) {
                    if (specialB[v]) {
                        Y[root] += Y[v] - sz;
                    }
                }
            }
        }

        for (int i = 1; i <= NB; i++)
            if (!specialB[i]) {
                int root = DSU_B.find_set(i);
                Y[i] = Y[root];
            }

        int sumY = 0, SY = 0;
        for (int i = 1; i <= NB; i++) {
            sumY = (sumY + Y[i])%mod;
            SY = (SY + i*Y[i]%mod)%mod;
        }
        /*=========================TREE - B - ==============================*/

        int ans = (sumX*SY%mod + sumY*SX%mod)%mod;
        cout << ans << '\n';
    }

    return 0;
}