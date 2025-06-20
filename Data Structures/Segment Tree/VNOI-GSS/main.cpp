#include <bits/stdc++.h>

using namespace std;

const int inf  = 1e9 + 7;
const int maxN = 5e4 + 7;

// Thông tin của mỗi nút
struct node {
    int pre, suf, sum, maxsum;  

    static node base() { return { -inf, -inf, 0, -inf }; }

    // Hàm hợp nhất 2 nút con
    static node merge(const node& a, const node& b)  {
        node res;
        res.pre = max(a.pre, b.pre + a.sum);
        res.suf = max(b.suf, a.suf + b.sum);
        res.sum = a.sum + b.sum;
        res.maxsum = max(a.maxsum, b.maxsum);
        res.maxsum = max(res.maxsum, a.suf + b.pre);
        return res;
    }
};

int n, m;
int a[maxN];
node st[4 * maxN];

// Thủ tục xây dựng cây phân đoạn
void build(int id, int l ,int r) {
    if (l == r) {
        st[id] = { a[l], a[l], a[l], a[l] };
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = node::merge(st[2 * id], st[2 * id + 1]);
}

// Hàm lấy giá trị
node get(int id, int l, int r, int u, int v){
    if (l >  v || r <  u) return node::base();
    if (l >= u && r <= v) return st[id];

    int mid = l + r >> 1;
    node g1 = get(2 * id, l, mid, u, v);
    node g2 = get(2 * id + 1, mid + 1, r, u, v);
    return node::merge(g1, g2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    build(1, 1, n);

    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << get(1, 1, n, x, y).maxsum << '\n';
    }

    return 0;
}