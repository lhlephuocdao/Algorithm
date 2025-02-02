#include <bits/stdc++.h>

using namespace std;

const int maxn = 200007;
const int maxa = 100;
const int blockSZ = 500;
int n,q,a[maxn], lazy[450][maxa+5], nblocks;

void updateBlock(int id, int oval, int nval)
{
    for (int i = 1; i <= maxa; i++)
        if (lazy[id][i] == oval) lazy[id][i] = nval;
}

void lazy_update(int id)
{
    int left = id*blockSZ;
    int right = min(n-1, left + blockSZ - 1);
    for (int i = left; i <= right; i++) {
        a[i] = lazy[id][a[i]];
    }

    for (int i = 1; i <= maxa; i++)
        lazy[id][i] = i;
}

void update(int l, int r, int oval, int nval)
{
    if (l<=r && l%blockSZ!=0) lazy_update(l/blockSZ);
    while (l<=r && l%blockSZ!=0) {
        if (a[l] == oval) a[l] = nval;
        l++;
    }

    if (l<=r && r%blockSZ!=blockSZ-1) lazy_update(r/blockSZ);
    while(l<=r && r%blockSZ!=blockSZ-1) {
        if (a[r] == oval) a[r] = nval;
        r--;
    }

    if (l < r)
    {
        int bl = l/blockSZ;
        int br = r/blockSZ;
        for (int id = bl; id <= br; id++)
            updateBlock(id, oval, nval);
    }
}

void init() {
    nblocks = (n + blockSZ - 1) / blockSZ;
    for (int i = 0; i < nblocks; i++) {
        for (int j = 1; j <= maxa; j++) {
            lazy[i][j] = j;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    init();

    cin >> q;
    while (q--)
    {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        l--; r--;
        update(l, r, x, y);
    }

    for (int i = 0; i < nblocks; i++) {
        lazy_update(i);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}