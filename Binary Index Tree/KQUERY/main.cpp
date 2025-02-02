#include <bits/stdc++.h>

using namespace std;

const int maxn = 30000;
const int maxq = 200000;
const int MAX = 1e9;

int n, q;

struct Query {
    int l, r, k, index;
};

bool operator < (const Query &a, const Query &b) {
    return a.k < b.k;
}

int solveByBIT()
{

}

/*--------------Segment Tree --------------------------*/

void build(int st[], int id, int l, int r)
{
    if (l == r) {
        st[id] = 1;
        return;
    }
 
    int mid = l + r >> 1;
    build(st, 2*id, l, mid);
    build(st, 2*id + 1, mid + 1, r);
 
    st[id] = st[2*id] + st[2*id+1];
}
 
void update(int st[], int id, int l, int r, int u)
{
    if (u < l || u > r) return;
 
    if (l == r) {
        st[id] = 0;
        return ;
    }
    int mid = l + r >> 1;
    update(st, 2*id, l, mid, u);
    update(st, 2*id + 1, mid+1, r, u);
 
    st[id] = st[2*id] + st[2*id+1];
}

int get(int st[], int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) {
        return st[id];
    }
 
    int mid = l + r >> 1;
    int get1 = get(st, 2*id, l, mid, u, v);
    int get2 = get(st, 2*id + 1, mid+1, r, u, v);
 
    return get1 + get2;
}

int* solveByST(int a[], Query queries[])
{
    int arr[maxn], id[maxn], st[4*maxn], result[200005];

    for (int i = 1; i <= n; i++) {
        arr[i] = a[i];
        id[i] = i;
    }

    sort(id+1, id+n+1, [&](int i, int j) {
        return arr[i]< arr[j];
    });
 
    build(st, 1, 1, n);

    int i = 1;
    for (int j = 1; j <= q; j++) {
        Query q = queries[j];
        while (i <= n && arr[id[i]] <= q.k) {
            update(st, 1, 1, n, id[i]); //Nnhững phần tử mà nhỏ hơn hoặc bằng k -> update = 0
            i++;
        }
        result[q.index] = get(st, 1, 1, n, q.l, q.r);
    }
    return result;
}

/*--------------------------------------------------------*/

int generate_random_int(long long min, long long max) {
    return min + (rand() % (long long)(max - min + 1));
}

void show(int a[], int size)
{
    for (int i = 1; i <= size-1; i++)
        cout << a[i] << " ";
    cout << '\n';
}

void show(const Query queries[])
{
    for (int i = 1; i <= q; i++) {
        cout << queries[i].l << " " << queries[i].r << " " << queries[i].k << '\n';
    }
}

void stress_test(long long size, long long min, long long max)
{
    int i = 1;
    while (1)
    {
        cout << "Iteration: " << i << "\n";
        //Generate n and array a[n]
        n = generate_random_int(1, max);
        int a[n+1];
        for (int i = 1; i <= n; i++) {
            int num = generate_random_int(1, MAX);
            a[i] = num;
        }

        //Generate q and array queries 
        q = generate_random_int(1, maxq);
        Query queries[q+1];
        Query queries2[q+1];
        for (int i = 1; i <= q; i++) {
            int x = generate_random_int(1, n);
            int y = generate_random_int(1, n);
            int k = generate_random_int(1, MAX);
            queries[i] = {x, y, k, i};
            queries2[i] = {x, y, k, i};
        }
        sort(queries+1, queries+q+1);

        int ansST = solveByST();
        int ansBIT = solveByBIT();
    
        if (ansST != ansBIT) {
            cout << "FAIL: \n";
            cout << "n: " << n << '\n';
            show(a, n+1);
            cout << 'q: ' << q << '\n';
            show(queries2);
            cout << "ST ans: " << ansST << '\n';
            cout << "BIT ans: " << ansBIT << '\n';
            break;
        }

        i++;
    }
}

int main() {
    srand(time(0));
    stress_test(100000, 1, 10000000000000);
    return 0;
}