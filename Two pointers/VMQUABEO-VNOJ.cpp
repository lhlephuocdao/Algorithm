#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 7;
const int inf  = 1e9 + 7;
int n,L,D;

void build(vector<int>& a, vector<int>& st, int id, int l, int r, bool is_max) {
    if (l == r) {
        st[id] = a[l];
        return;
    }

    int mid = l + r >> 1; // (l + r) / 2
    build(a, st, 2 * id, l, mid, is_max);
    build(a, st, 2 * id + 1, mid + 1, r, is_max);

    if (is_max) st[id] = max(st[2 * id], st[2 * id + 1]);
    else st[id] = min(st[2 * id], st[2 * id + 1]);
}

int get(vector<int>& st, int id, int l, int r, int u, int v, bool is_max) {
    if (l > v || r < u)
        if (is_max) return 0;
        else return inf;

    if (l >= u && r <= v) return st[id];

    int mid = l + r >> 1; // (l + r) / 2
    int get1 = get(st, 2 * id, l, mid, u, v, is_max);
    int get2 = get(st, 2 * id + 1, mid + 1, r, u, v, is_max);

    if (is_max) return max(get1, get2);
    else return min(get1, get2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> tree1(4*maxn, 0); // max tree
    vector<int> tree2(4*maxn, inf); // min tree

    cin >> n >> L >> D;
    vector<int> h(n+1);
    for (int i = 1; i <= n; i++) cin >> h[i];

    build(h, tree1, 1, 1, n, true);
    build(h, tree2, 1, 1, n, false);
    
    long long ans = 0;
    int _max = INT_MIN, _min = INT_MAX;
    for (int l = 1, r = 1; r <= n; r++)
    {
        _max = max(_max, h[r]);
        _min = min(_min, h[r]);

        while (_max - _min > D)
        {
            l++;
            _max = get(tree1, 1, 1, n, l, r, true);
            _min = get(tree2, 1, 1, n, l, r, false);
        }

        int t = (r - L) - l + 1;
        if (t > 0) ans += t;
    }

    cout << ans << '\n';

    return 0;
}