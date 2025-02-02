#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;
const int MAXM = 5e4 + 5;

struct Point {
    int x, y;
};

struct Rect {
    int w, h;
};

struct Event {
    int type; // 0 = point, 1 = rect
    int id;
    int x;
    int y1, y2;
};

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n);
    }

    void update(int node, int l, int r, int pos, int val) {
        if (l == r) {
            tree[node] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(node * 2, l, mid, pos, val);
        } else {
            update(node * 2 + 1, mid + 1, r, pos, val);
        }
        tree[node] = tree[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > qr) {
            return 0;
        }
        if (ql == l && qr == r) {
            return tree[node];
        }
            int mid = (l + r) / 2;
        return query(node * 2, l, mid, ql, min(qr, mid)) + query(node * 2 + 1, mid + 1, r, max(ql, mid + 1), qr);
    }
};

int n, m;
Point points[MAXN];
Rect rects[MAXM];
int ans[MAXN];
vector<Event> events;

bool cmpX(Point a, Point b) {
    return a.x < b.x;
}

bool cmpPy(Point a, Point b) {
    return a.y < b.y;
}

bool cmpEx(Event a, Event b) {
    return a.x < b.x;
}

bool cmpY(Event a, Event b) {
    return a.y1 < b.y1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> points[i].x >> points[i].y;
        events.push_back({0, i, points[i].x, points[i].y, points[i].y});
    }

    for (int i = 1; i <= m; i++) {
        cin >> rects[i].w >> rects[i].h;
        events.push_back({1, i, rects[i].w, 0, rects[i].h});
    }

    sort(points + 1, points + n + 1, cmpX);
    sort(events.begin(), events.end(), cmpY);

    SegmentTree segtree(n + m);

    for (auto e : events) {
        if (e.type == 0) {
            segtree.update(1, 1, n + m, e.id, 1);
        } else {
            ans[e.id] = segtree.query(1, 1, n + m, 1, e.y2);
        }
    }

    events.clear();

    for (int i = 1; i <= n; i++) {
        events.push_back({0, i, points[i].y, points[i].x, points[i].x});
    }

    for (int i = 1; i <= m; i++) {
        events.push_back({1, i, rects[i].h, 0, rects[i].w});
    }

    sort(points + 1, points + n + 1, cmpPy);
    sort(events.begin(), events.end(), cmpEx);

    segtree = SegmentTree(n + m);

    for (auto e : events) {
        if (e.type == 0) {
            segtree.update(1, 1, n + m, e.id, 1);
        } else {
            ans[e.id] = segtree.query(1, 1, n + m, 1, e.y2);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}