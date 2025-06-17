#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fenwick (BIT) supporting point-updates and prefix sums
struct Fenwick {
    int n;
    vector<ll> f;
    Fenwick(int _n): n(_n), f(n+1, 0) {}
    void update(int i, ll v = 1) {
        for (; i <= n; i += i & -i)
            f[i] += v;
    }
    ll query(int i) const {
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s += f[i];
        return s;
    }
    ll query(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> p(n+1), pos(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    struct Query { int l, r, idx; };
    vector<Query> qs(m);
    for (int i = 0; i < m; i++) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].idx = i;
    }
    sort(qs.begin(), qs.end(), [](auto &a, auto &b){
        return a.r < b.r;
    });

    vector<ll> answer(m);
    Fenwick fenw(n);
    int qi = 0;

    // Sweep w = 1..n as the “right” index
    for (int w = 1; w <= n; w++) {
        int v = p[w];

        cout << "v: " << v << " w: " << w << '\n';

        // 1) Self-pair (w,w)
        cout << "update " << w << '\n';
        fenw.update(w, 1);

        // 2) Pairs (q,w) with q<w and p[q]|p[w]:
        int lim = floor(sqrt(v));
        for (int d = 1; d <= lim; d++) {
            if (v % d) continue;
            int e = v / d;
            // divisor d
            cout << "e: " << e << " d: " << d << '\n';
            int q1 = pos[d];
            if (q1 < w) {
                fenw.update(q1, 1); 
                cout << "update " << q1 << '\n';
            }
            // divisor e (if distinct)
            if (e != d) {
                int q2 = pos[e];
                if (q2 < w) {
                    fenw.update(q2, 1);
                    cout << "update " << q2 << '\n';
                }
            }
        }

        // 3) Pairs (q,w) with q<w and p[w]|p[q]:
        //    i.e. p[q] is a multiple of v = p[w]
        for (int k = 2; k * v <= n; k++) {
            int multiple = k * v;
            int q = pos[multiple];
            cout << "multiple: " << multiple << " q:" << q << '\n';
            if (q < w) {
                fenw.update(q, 1);
                cout << "update " << q << '\n';
            }
        }

        // Answer all queries ending at r == w
        while (qi < m && qs[qi].r == w) {
            cout << "query " << qs[qi].l << "," << w << '\n';
            answer[qs[qi].idx] = fenw.query(qs[qi].l, w);
            qi++;
        }
    }

    // Output in original order
    for (ll ans : answer)
        cout << ans << "\n";

    return 0;
}
