#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;
    while (t--)
    {
        int n,x;
        cin >> n >> x;
        unordered_map<int, int> m;
        unordered_map<int, bool> v;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            m[tmp]++;
            v[tmp] = true;
        }

        for (auto it : m)
        {
            int a = it.first;
            if (v[a] == false) continue;
    
            int b = a ^ x;
            if (b > 2000000000LL) continue;

            if (m.find(b) != m.end())
            {
                int na = it.second;
                int nb = m[b];
                if (x == 0) {
                    ans += 1LL*na*(na-1)/2;
                    v[a] = false;
                }
                else {
                    ans += 1LL*na*nb;
                    v[a] = false;
                    v[b] = false;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}