#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>
const long long INF = 2e18;

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

struct point {
    int s;
    int c;
    int d;
};

struct query {
    int idx;
    int l;
    int h;
    int r;
};

class SegmentTree {
private:
    int n;
    vector<int> st;

    void build(int p, int l, int r, const vector<int>& arr) {
        if (l == r) {
            st[p] = arr[l];
            return;
        }
        int m = (l+r)>>1;
        build(2*p, l, m, arr);
        build(2*p+1, m+1, r, arr);
        st[p] = min(st[2*p], st[2*p+1]);
    }

    // query minimum on inverval [i, j]
    int query(int p, int l, int r, int i, int j) const {
        if (r<i || l>j) return INF;
        if (l>=i && r<=j) return st[p];
        int m = (l+r)>>1;
        int v1 = query(2*p, l, m, i, j);
        int v2 = query(2*p+1, m+1, r, i, j);
        return min(v1, v2);
    }

    // update set arr[idx] = val
    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            st[p] = val;
            return;
        }
        int m = (l+r)>>1;
        if (idx<=m)
            update(2*p, l, m, idx, val);
        else
            update(2*p+1, m+1, r, idx, val);
        st[p] = min(st[2*p], st[2*p+1]);
    }
public:
    SegmentTree(int size) : n(size), st(4*size, INF) {}
    SegmentTree(const vector<int>& arr)
        : n(arr.size()), st(4*n, INF)
    {
        if (n>0) build(1, 0, n-1, arr);
    }

    int query(int l, int r) const {
        if (l<0) l = 0;
        if (r >= n) r = n-1;
        if (l>r) return INF;
        return query(1, 0, n-1, l, r);
    }

    void update(int idx, int val) {
        if (idx < 0 || idx >= n) return;
        update(1, 0, n-1, idx, val);
    }
};

int32_t main()
{
    fastio;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n,m,q;
        cin >> n >> m >> q;
        vector<point> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i].s >> p[i].c;

        vector<vector<pii>> adj(n);
        for (int i = 0; i < m; i++) {
            int u,v,w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dis(n, INF);
        dis[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq; // {dis, node}
        pq.push({0,0});
        while (!pq.empty()) {
            int u = pq.top().second;
            int du = pq.top().first;
            pq.pop();
            if (dis[u] < du) continue;

            for (auto x : adj[u]) {
                int v = x.first;
                int w = x.second;
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        vector<int> v, sq;
        for (int i = 0; i < n; i++) {
            p[i].d = dis[i];
            v.push_back(dis[i]);
            sq.push_back(p[i].s);
        }

        vector<query> que(q);
        for (int j = 0; j < q; j++)
        {
            int l,h,r;
            cin >> l >> h >> r;
            que[j] = {j, l, h, r};
            v.push_back(r);
            sq.push_back(l);
            sq.push_back(h);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int j = 0; j < q; j++)
            que[j].r = lower_bound(v.begin(), v.end(), que[j].r) - v.begin();

        for (int i = 0; i < n; i++)
            p[i].d = lower_bound(v.begin(), v.end(), p[i].d) - v.begin();

        sort(que.begin(), que.end(), [&](query& a, query& b) {
            return a.r < b.r;
        });
        sort(p.begin(), p.end(), [&](point& a, point& b){
            return a.d < b.d;
        });

        sort(sq.begin(), sq.end());
        sq.erase(unique(sq.begin(), sq.end()), sq.end());

        for (int i = 0; i < n; i++)
            p[i].s = lower_bound(sq.begin(), sq.end(), p[i].s) - sq.begin();
        for (int j = 0; j < q; j++)
        {
            que[j].l = lower_bound(sq.begin(), sq.end(), que[j].l) - sq.begin();
            que[j].h = lower_bound(sq.begin(), sq.end(), que[j].h) - sq.begin();
        }

        SegmentTree st((int)sq.size());
        vector<int> ans(q, -1);
        for (int i = 0, j = 0; j < q; j++) {
            int R = que[j].r;
            while (i<n && p[i].d <= R) {
                int old = st.query(p[i].s, p[i].s);
                if (old > p[i].c) st.update(p[i].s, p[i].c);
                i++;
            }

            int res = st.query(que[j].l, que[j].h);
            if (res == INF) res = -1;
            ans[que[j].idx] = res;
        }

        for (int j = 0; j < q; j++)
            cout << ans[j] << '\n';
    }   

    return 0;
}