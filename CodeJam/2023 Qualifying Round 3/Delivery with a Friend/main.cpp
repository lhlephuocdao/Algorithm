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

    while(t--)
    {
        int n,PA,PB,ta,tb;
        cin >> n >> ta >> tb;

        if (ta < tb) {
            PA = ta;
            PB = tb;
        } else {
            PA = tb;
            PB = ta;
        }

        int x[n];
        vector<ll> common;
        ll maxA = 0, maxB = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            int da = x[i] - PA;
            int db = PB - x[i];
            if (da < db) {
                maxA += 1LL*da*2;
                sum += 1LL*da*2;
            } else if (da > db) {
                maxB += 1LL*db*2;
                sum += 1LL*db*2;
            } else {
                common.push_back(1LL*da*2);
                sum += 1LL*da*2;
            }
        }

        for (auto c : common)
        {
            ll da = abs((c+maxA) - maxB);
            ll db = abs((c+maxB) - maxA);
            if (da < db) {
                maxA += c;
            } else {
                maxB += c;
            }
        }

        cout << sum << " " << abs(maxA-maxB) << '\n';
    }
 
    return 0;
}