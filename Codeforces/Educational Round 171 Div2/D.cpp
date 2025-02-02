#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 3e5;
int bit[maxn+1], bit2[maxn+1];

void update(int u, int v, int tree[])
{
    while (u <= maxn)
    {
        tree[u] += v;
        u += (u & (-u));
    }
}

int get(int p, int tree[])
{
    int ans = 0;
    while (p > 0)
    {
        ans += tree[p];
        p -= (p & (-p));
    }
    return ans;
}

int getRange(int l, int r, int tree[])
{
    return get(r, tree) - get(l-1, tree);
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> a(n+1), pre1(n+1), pre2(n+1);
    pre1[0] = 0;
    pre2[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, (n-i+1)*a[i], bit);
        pre1[i] = pre1[i-1] + a[i];
        pre2[i] = pre2[i-1] + pre1[i];
    }

    vector<int> memory(n+1);
    for (int i = 1; i <= n; i++)
        memory[i] = getRange(i, n, bit);

    for (int i = 1; i <= n; i++)
        update(i, memory[i], bit2);

    int size_b = (n*(n+1))/2;
    vector<int> index_b;
    index_b.push_back(0);
    int tmp = n;
    int lo = 0, hi = 0;
    while (tmp > 0)
    {
        lo = hi+1;
        hi = lo+tmp-1;
        index_b.push_back(lo);
        index_b.push_back(hi);
        tmp--;
    }

    int q; cin >> q;
    while (q--)
    {
        int l, r, ans = 0;
        cin >> l >> r;
        
        int id_l = lower_bound(index_b.begin(), index_b.end(), l) - index_b.begin();
        auto itr_r = upper_bound(index_b.begin(), index_b.end(), r);
        itr_r--;
        int id_r = itr_r - index_b.begin();

        int start = id_l + ((id_l%2==0) ? 1 : 0);
        int end = id_r + ((id_r%2==1) ? -1 : 0);

        if (start <= end) {
            start = (start+1)/2;
            end = end/2;
            ans += getRange(start, end, bit2);
        }

        if (id_l <= id_r) {
            /* add diff l */
            if (id_l % 2 == 0)
            {
                int j = id_l/2;
                int y = n;
                int diff = index_b[id_l] - l;
                int x = y-diff;
                int sum1 = pre2[y] - pre2[x-1];
                ans += sum1 - (y-x+1)*(pre1[j-1]);
            }

            /* add diff r */
            if (id_r % 2 == 1)
            {
                int j = (id_r+1)/2;
                int x = j;
                int diff = r - index_b[id_r];
                int y = x + diff;
                int sum1 = pre2[y] - pre2[x-1];
                ans += sum1 - (y-x+1)*(pre1[j-1]);
            }
        } else {
            int j = (id_r+1)/2;
            int diff_r = r - index_b[id_r];
            int diff_l = index_b[id_l] - l;
            int x = n-diff_l;
            int y = j+diff_r;

            int sum1 = pre2[y] - pre2[x-1];
            ans += sum1 - (y-x+1)*(pre1[j-1]);
        }

        cout << ans << '\n';
    }

    return 0;
}