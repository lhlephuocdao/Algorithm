#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
 
const int maxN = 1e5 + 7;
int n,q,a,b,k;
string s;
int cnt[30];
int st[30][4*maxN], lazy[30][4*maxN];

void build(int id, int l, int r)
{
    for (int ch = 0; ch <= 25; ch++) lazy[ch][id] = -1;

    if (l == r) {
        st[s[l-1] - 'a'][id] = 1;
        return;
    }

    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    for (int ch = 0; ch <= 25; ch++)
        st[ch][id] = st[ch][id*2] + st[ch][id*2+1];
}

void lazy_update(int id, int l, int r, int ch)
{
    if (lazy[ch][id] == -1) return;
    st[ch][id] = lazy[ch][id]*(r-l+1);

    if (l != r) {
        lazy[ch][2*id] = lazy[ch][id];
        lazy[ch][2*id+1] = lazy[ch][id];
    }

    lazy[ch][id] = -1;
}

int get(int id, int l, int r, int u, int v, int ch)
{
    lazy_update(id, l, r, ch);
    if (l>v || r<u) return 0;
    if (l>=u && r<=v) return st[ch][id];

    int mid = l + r >> 1;
    int get1 = get(id*2, l, mid, u, v, ch);
    int get2 = get(id*2+1, mid+1, r, u, v, ch);
    return get1+get2;
}

void update(int id, int l, int r, int u, int v, int val, int ch)
{
    lazy_update(id, l, r, ch);
    if (l>v || r<u) return;
    if (l>=u && r<=v) {
        lazy[ch][id] = val;
        lazy_update(id, l, r, ch);
        return;
    }

    int mid = l + r >> 1;
    update(2*id, l, mid, u, v, val, ch);
    update(2*id+1, mid+1, r, u, v, val, ch);

    st[ch][id] = st[ch][2*id] + st[ch][2*id+1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> n >> q >> s;
    build(1, 1, n);

    // for (int ch = 0; ch <= 25; ch++) {
    //     char c = ch + 'a';
    //     cout << c << ": ";
    //     for (int i = 0; i <= n; i++)
    //         cout << st[ch][i] << " ";
    //     cout << '\n';
    // }

    while (q--)
    {
        cin >> a >> b >> k;
        for (int ch = 0; ch <= 25; ch++) {
            cnt[ch] = get(1, 1, n, a, b, ch);
            update(1, 1, n, a, b, 0, ch);
        }

        int l = a, ch = k ? 0 : 25, sign = k ? 1 : -1;
        for (; ch >= 0 && ch <= 25; ch += sign) {
            if (cnt[ch]) {
                update(1, 1, n, l, l + cnt[ch] - 1, 1, ch);
                l += cnt[ch];
            }
        }
    }

    for (int i = 0; i <= n; i++)
        for (int ch = 0; ch <= 25; ch++)
            if (get(1, 1, n, i, i, ch)) {
                cout << (char)(ch + 'a');
                break;
            }

    return 0;
}