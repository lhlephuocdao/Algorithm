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

    int T;
    cin >> T;

    while (T--)
    {
        int n = 0;
        map<int, int, std::greater<int>> m;
        for (int i = 1; i <= 9; i++)
        {
            int t;
            cin >> t;
            n += t;
            if (t != 0) {
                if (i == 6) 
                    m[9] += t;
                else
                    m[i] += t;
            }
        }

        int a[n+1];
        memset(a, 0, sizeof(a));

        int l = 1, r = n;
        bool left = true;

        while (l <= r)
        {
            std::map<int, int>::iterator it = m.begin();
            if (left) {
                a[l] = it->first;
                it->second--;
                if (it->second == 0) m.erase(it->first);
                left = false;
                l++;
            } else {
                a[r] = it->first;
                it->second--;
                if (it->second == 0) m.erase(it->first);
                left = true;
                r--;
            }
        }

        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << '\n';
    }
 
    return 0;
}