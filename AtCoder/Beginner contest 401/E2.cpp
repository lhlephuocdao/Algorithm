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

class FenwickTree {
    private:
        int n;
        vector<int> bit;
    
    public:
        FenwickTree(int n_) : n(n_) {
            bit.assign(n + 1, 0); // use n+1 for 1-indexing
        }
    
        void update(int u, int v) {
            int idx = u+1;
            while (idx <= n) {
                bit[idx] += v;
                idx += (idx & (-idx));
            }
        }
    
        int query(int p) {
            int idx = p+1, ans = 0;
            while (idx > 0) {
                ans += bit[idx];
                idx -= (idx & (-idx));
            }
            return ans;
        }
    };

int32_t main()
{
    fastio;

    int t = 1;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        vector<pii> edge;
        for (int i = 0; i < m; i++)
        {
            int u,v;
            cin >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            edge.push_back({u, v});
        }

        sort(edge.begin(), edge.end(), [&](const pii& a, const pii& b) {
            return a.sc < b.sc;
        });

        vector<int> minNeighbor(n, INT_MAX);
        for (auto p : edge) {
            int u = p.first;
            int v = p.second;
            minNeighbor[u] = min(minNeighbor[u], v);
            minNeighbor[v] = min(minNeighbor[v], u);
        }

        vector<int> cnt_min(n, 0);
        // cnt_min[i] = x : có x đỉnh (x>i) mà có min neighbor là i
        for (int i = 0; i < n; i++)
            if (minNeighbor[i] < n) cnt_min[minNeighbor[i]]++;

        FenwickTree ft(n);
        for (int i = 0; i < n; i++) {
            ft.update(i, cnt_min[i]);
        }

        DSU g(n);
        for (int i = 0; i < n; i++) g.make_set(i);
        int j = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            while (j < m && edge[j].sc <= i) {
                g.join_sets(edge[j].fi, edge[j].sc);
                j++;
            }

            int min_neighbor = minNeighbor[i];
            if (min_neighbor <= i) {
                ft.update(min_neighbor, -1);
            } else {
                pq.push(min_neighbor);
            }

            while (!pq.empty() && pq.top() <= i) {
                int u = pq.top();
                pq.pop();
                ft.update(u, -1);
            }

            int root = g.find_set(0);
            int sz = g.sz[root];
            if (sz < (i+1)) {
                cout << -1 << '\n';
                continue;
            } else {
                assert(sz == i+1);
                cout << ft.query(i) << '\n';
            }
        }
    }
    return 0;
}