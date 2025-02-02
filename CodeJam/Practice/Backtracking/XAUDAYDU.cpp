#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 25;
const int flag = (1<<26) - 1;
int n;
int mask[maxn];
long long ans = 0;

void backtrack(int pos, int cur_mask)
{
    if (pos > n) return;
    if (pos == n && cur_mask == flag) ans++;

    backtrack(pos+1, (cur_mask | mask[pos]));

    backtrack(pos+1, cur_mask);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    memset(mask, 0, sizeof(mask));
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            mask[i] |= 1<<(s[j] - 'a');
        }
    }

    backtrack(0, 0);
    
    cout << ans << '\n';

    return 0;
}
