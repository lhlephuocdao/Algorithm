#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 7;
int bit[maxn];
int n,q;

void update(int id, int v)
{
    while (id <= n)
    {
        bit[id] += v;
        id += (id & (-id));
    }
}

int get(int p)
{
    int res = 0, id = p;
    while (id > 0)
    {
        res += bit[id];
        id -= (id & (-id));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        update(a, 1);
    }

    for (int i = 0; i < q; i++)
    {
        int k; cin >> k;
        if (k >= 1 && k<=n) update(k, 1);
        else if (k<0) {
            k = -k;
            int l = 1, r = n, mid, pos;
            while (l<=r)
            {
                mid = l + ((r - l) / 2);
                int total = get(mid);
                if (total >= k) {
                    pos = mid;
                    r = mid-1;
                }
                else
                    l = mid+1;
            }
            update(pos, -1);
        }
    }

    if (get(n) == 0) cout << 0 << '\n';
    else {
        for (int i = 1; i <= n; i++)
            if (get(i) != 0) {
                cout << i << '\n';
                return 0;
            }
    } 

    return 0;
}