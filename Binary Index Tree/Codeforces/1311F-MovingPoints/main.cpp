#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=2e5+7;
int n,V[N];

struct node {
    int x,v;
    bool operator<(const node& o) const {
        return x>o.x;
    }
} a[N];

ll c[N], t[N];

void add(int i, ll val1, ll val2)
{
    while (i<=n)
    {
        c[i] += val1;
        t[i] += val2;
        i += (i & (-i));
    }
}

ll qc(int i)
{
    ll re = 0;
    while (i > 0) {
        re += c[i];
        i -= (i & (-i));
    }
    return re;
}

ll qt(int i)
{
    ll re = 0;
    while (i > 0) {
        re += t[i];
        i -= (i & (-i));
    }
    return re;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v;
        V[i]= a[i].v;
    }

    /*
        a[]: 5 4 3 2 1
           : 4 2 3 2 2
        V[]: 2 2 2 3 4
    */

    sort(a+1, a+n+1);
    sort(V+1, V+n+1);

    int size = unique(V+1, V+n+1)-V-1;
    /* 
        a[]: 5 4 3 2 1
           : 4 2 3 2 2
        V[]: 2 3 4
        Ta chỉ quan tâm đến tính tương đối của mảng v[], k cần quan tâm đến giá trị của chúng
        -> Do đó ta dùng kỹ thuật rời rạc hóa dữ liệu để chuyển mảng v[] sang giá trị mới dễ sử dụng hơn
     */

    // map<ll, int> m;
    // m[V[1]] = 1;

    // for (int i = 2; i<=n; i++)
    // {
    //     if (V[i] == V[i-1])
    //         continue;
    //     m[V[i]] = m[V[i-1]]+1;
    // }

    // for (int i = 1; i<=n; i++)
    //     a[i].v = m[a[i].v];

    for (int i = 1; i<=n; i++)
        a[i].v = lower_bound(V+1, V+1+size, a[i].v)-V;

    /* 
        a[]: 5 4 3 2 1
           : 3 1 2 1 1 -> Tính tương đối của các phần tử trong mảng vẫn sẽ k đổi so với ban đầu
        V[]: 2 3 4
     */

    ll ans = 0;
    for (int i = 1; i <= n; i++) add(a[i].v /* index */, a[i].x /* add c */, 1 /* add t */);
    for (int i = 1; i <= n; i++) {
        add(a[i].v, -a[i].x, -1);
        ll kc = qc(a[i].v); // tổng của các elements trong a[i+1],a[n] mà có v < a[i].v
        ll kt = qt(a[i].v); // số elements trong a[i+1],a[n] mà có v < a[i].v
        ans += kt*a[i].x-kc;
        // cout << ans << " ";
    }
    cout << '\n' << ans << '\n';

    return 0;
}
/*
    Therefore, we can sort x[i] from large to small to make x[i]>x[i+1] and discretize vi . 
    Put v[i] as the subscript, x[i] and the number of points as values ​​into the tree array. 
    Enumerate points, query the number t of point j <= v[i] and the sum sumx of xj value .
    The contribution is t*x[i]-sumx , and the contributions can be accumulated.
*/