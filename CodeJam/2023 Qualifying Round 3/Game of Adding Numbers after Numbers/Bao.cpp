#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 4;
const int maxm = 1e6 + 4;
const int temp = 500000;
int v[maxn];
int t;
struct node {
    int sl, val;
} st[maxm * 4];
void update(int id, int l, int r, int pos) {
    if (l > pos || pos > r || l > r) return;
    if (l == r) {
        st[id].val += pos;
        st[id].sl++;
        return;
    }
    int mid = (l + r) / 2ll;
    if (mid >= pos)
        update(id * 2, l, mid, pos);
    else
        update(id * 2 + 1ll, mid + 1, r, pos);
    st[id].val = st[id * 2].val + st[id * 2 + 1].val;
    st[id].sl = st[id * 2].sl + st[id * 2 + 1].sl;
}
void resett(int id, int l, int r, int pos) {
    if (l > pos || pos > r || l > r) return;
    if (l == r) {
        st[id].val = 0ll;
        st[id].sl = 0ll;
        return;
    }
    int mid = (l + r) / 2ll;
    if (mid >= pos)
        resett(id * 2, l, mid, pos);
    else
        resett(id * 2 + 1, mid + 1, r, pos);
    st[id].val = st[id * 2].val + st[id * 2 + 1].val;
    st[id].sl = st[id * 2].sl + st[id * 2 + 1].sl;
}
int getsl(int id, int l, int r, int x, int y) {
    if (y < l || x > r || l > r) return 0;
    if (x <= l && r <= y) return st[id].sl;
    int mid = (l + r) / 2ll;
    return getsl(id * 2, l, mid, x, y) + getsl(id * 2 + 1, mid + 1, r, x, y);
}
int getval(int id, int l, int r, int x, int y) {
    if (y < l || x > r || l > r) return 0;
    if (x <= l && r <= y) return st[id].val;
    int mid = (l + r) / 2ll;
    return getval(id * 2, l, mid, x, y) + getval(id * 2 + 1, mid + 1, r, x, y);
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        int add = 0;
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> v[i], update(1ll, 1ll, 1e6, v[i] + temp);
        for (int i = 1; i <= m; i++) {
            int q, w;
            cin >> q >> w;
            if (q == 1ll) {
                update(1ll, 1ll, 1e6, w - add + temp);
                n++;
                v[n] = w - add;
            } else if (q == 2ll) {
                add += w;
            } else if (q == 4ll) {  // w so be nhat
                int l = 1ll, r = 1e6, pos = 0ll;
                while (l <= r) {
                    int mid = (l + r) / 2ll;
                    if (getsl(1ll, 1ll, 1e6, 1ll, mid) <= w) {
                        pos = mid;
                        l = mid + 1ll;
                    } else
                        r = mid - 1ll;
                }
                // cout << pos << endl;
                if (getsl(1ll, 1ll, 1e6, 1ll, pos) < w) {
                    // cout << getval(1ll, 1ll, 1e6, pos + 1, pos + 1) << " hung\n";
                    cout << getval(1ll, 1ll, 1e6, 1ll, pos) - w * temp + add * w + (w - getsl(1ll, 1ll, 1e6, 1ll, pos)) * getval(1ll, 1ll, 1e6, pos + 1ll, pos + 1ll) / getsl(1ll, 1ll, 1e6, pos + 1, pos + 1) << " ";
                } else
                    cout << getval(1ll, 1ll, 1e6, 1ll, pos) - w * temp + add * w << " ";
            } else if (q == 3ll) {
                int l = 1ll, r = 1e6, pos = 1e6;
                while (l <= r) {
                    int mid = (l + r) / 2ll;
                    if (getsl(1ll, 1ll, 1e6, mid, 1e6) <= w) {
                        pos = mid;
                        r = mid - 1ll;
                    } else
                        l = mid + 1ll;
                }
                if (getsl(1ll, 1ll, 1e6, pos, 1e6) < w) {
                    cout << getval(1ll, 1ll, 1e6, pos, 1e6) - w * temp + add * w + (w - getsl(1ll, 1ll, 1e6, pos, 1e6)) * getval(1ll, 1ll, 1e6, pos - 1, pos - 1) / getsl(1ll, 1ll, 1e6, pos - 1, pos - 1) << " ";
                } else
                    cout << getval(1ll, 1ll, 1e6, pos, 1e6) - w * temp + add * w << " ";
            }
        }
        cout << '\n';
        memset(st, 0, sizeof(st));
    }
    return 0;
}
/*
1
5 12
2 4 6 8 10
4 3
3 3
1 3
1 7
4 3
3 3
2 5
4 3
3 3
1 1
3 4
4 4
-------------------------
4 3 1 1 4 3 2 4 3 1 3 4
3 3 3 7 3 3 5 3 3 1 4 4
-----------------------------
2
5 12
2 4 6 8 10
4 3
3 3
1 3
1 7
4 3
3 3
2 5
4 3
3 3
1 1
3 4
4 4
1
5 8
1 1 1 1 500000
4 5
3 5
2 100000
4 3
3 3
2 400000
4 3
3 3
*/