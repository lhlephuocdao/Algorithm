#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e5 + 7;
int n,q;
ll a[maxn], b[maxn];

struct query {
    int type;
    int l;
    int r;
    int val;
};

//======================Segment Tree==========================
long long st[4 * maxn], lazy[4 * maxn];
 
void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    st[id] = st[2 * id] + st[2 * id + 1];
}
 
void fix(int id, int l, int r) {
    if (!lazy[id]) return;
    st[id] += lazy[id];
 
    if (l != r){
        lazy[2 * id] += lazy[id];
        lazy[2 * id + 1] += lazy[id];
    }
 
    lazy[id] = 0;
}
 
void update(int id, int l, int r, int u, int v, int val) {
    fix(id, l, r);
    if (l >  v || r <  u) return;
    if (l >= u && r <= v) {
        lazy[id] += val;
        fix(id, l, r);
        return;
    }
    int mid = l + r >> 1;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = st[2 * id] + st[2 * id + 1];
}
 
long long get(int id, int l, int r, int u, int v) {
    fix(id, l, r);
    if (l > v || r <  u) return 0;
    if (l >= u && r <= v) return st[id];
 
    int mid  = l + r >> 1;
    long long get1 = get(2 * id, l, mid, u, v);
    long long get2 = get(2 * id + 1, mid + 1, r, u, v);
    return get1 + get2;
}
//===========================Segment Tree=======================

bool compare(vector<ll> ans1, vector<ll> ans2) {
    int n1 = ans1.size();
    int n2 = ans2.size();
    if (n1 != n2) return false;
    for (int i = 0; i < n1; i++)
        if (ans1[i] != ans2[i]) return false;

    return true;
}

void show(vector<ll>& v)
{
    for (auto x : v) cout << x << " ";
    cout << '\n';
}

void show(vector<query>& v)
{
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].type << " " << v[i].l << " " << v[i].r << " ";
        if (v[i].type == 1) cout << v[i].val;
        cout << '\n';
    }
}

long long generate_random_int(long long min, long long max) {
    return min + (rand() % (long long)(max - min + 1));
}

void stress_test(long long size, long long min, long long max) {
    int idx = 1;
    while (1) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(st, 0, sizeof(st));
        memset(lazy, 0, sizeof(lazy));

        cout << "Iteration: " << idx << "\n";
        n = generate_random_int(1, 10);
        for (int i = 1; i <= n; i++) {
            a[i] = generate_random_int(1, 20);
            b[i] = a[i];
        }

        //Build initial ST
        build(1, 1, n);

        vector<ll> ST_ans;
        vector<ll> BF_ans;
        vector<query> queries;

        q = generate_random_int(1, 10);
        int tq = q;
        while (tq--) {
            int type = generate_random_int(1, 2);
            int l = generate_random_int(1, n);
            int r = generate_random_int(l, n);
            int val = 0;
            if (type == 1) {
                val = generate_random_int(1, 20);
                update(1, 1, n, l, r, val);
                for (int i = l; i <= r; i++)
                    a[i] += val;
            } else {
                ll ans = 0;
                for (int i = l; i <= r; i++)
                    ans += a[i];
                BF_ans.push_back(ans);

                ST_ans.push_back(get(1, 1, n, l, r));
            }
            query que = {type, l, r, val};
            queries.push_back(que);
        }

        if (compare(BF_ans, ST_ans) != true) {
            cout << "FAIL:\n";
            cout << "n: " << n << " q: " << q << '\n';
            cout << "arr a[]: ";
            for (int i = 1; i <= n; i++) cout << b[i] << " ";
            cout << '\n';
            cout << "queries: ";
            show(queries);
            cout << "EXPECTED: ";
            show(BF_ans);
            cout << "ACTUAL: ";
            show(ST_ans);
            break;
        }
        cout << "PASS\n";
        ++idx;

    }
}

int main()
{
    srand(time(0));
    stress_test(100000, 1, 10000000000000);
    return 0;
}