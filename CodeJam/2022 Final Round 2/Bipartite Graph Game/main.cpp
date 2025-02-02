#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
 
const int maxn = 10001;
const int maxk = 100001;
int n, m, k;
int X[maxn], Y[maxn];
unordered_map<int, pair<int, int>> E;
unordered_map<int, int> MX, MY;

bool sortByValue(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T;
    cin >> T;

    while (T--)
    {
        cin >> n >> m >> k;

        memset(X, 0 , sizeof(X));
        memset(Y, 0 , sizeof(Y));
        E.clear();
        MX.clear();
        MY.clear();

        FOR(i,1,k+1) {
            int a, b;
            cin >> a >> b;
            E[i] = make_pair(a, b);
            MX[a]++;
            MY[b]++;
        }

        vector<pair<int, int>> VX(MX.begin(), MX.end());
        vector<pair<int, int>> VY(MY.begin(), MY.end());

        sort(VX.begin(), VX.end(), sortByValue);
        sort(VY.begin(), VY.end(), sortByValue);

        // cout << "\nVX: \n";
        // FORE(it,VX)
        // {
        //     cout << it->first << "  " << it->second << '\n';
        // }

        // cout << "VY: \n";
        // FORE(it,VY)
        // {
        //     cout << it->first << "  " << it->second << '\n';
        // }

        int minX[n+1], minY[m+1];
        memset(minX, 0 , sizeof(minX));
        memset(minY, 0 , sizeof(minY));

        // cout << "\nCount minX:\n";
        int nn = n;
        int prev = VX[0].second;
        for (int i = 0; i < VX.size(); i++) {
            X[VX[i].first] = nn;
            if (VX[i].second != prev && i>0) {
                // cout << "prev: " << prev << "   " << "nn: " << nn << '\n';
                minX[prev] = nn+1;
                prev = VX[i].second;
            }
        
            if (i == (VX.size() - 1)) {
                minX[VX[i].second] = nn;
            }
            nn--;
        }

        // FOR(i,1,n+1)
        //     cout << minX[i] << " ";
        // cout << '\n';

        int mm = m;
        prev = VY[0].second;
        for (int i = 0; i < VY.size(); i++) {
            // cout << "i = " << i << "    mm = " << mm << '\n'; 
            Y[VY[i].first] = mm;
            if (VY[i].second != prev && i>0) {
                minY[prev] = mm + 1;
                prev = VY[i].second;
            }
            
            if (i == (VY.size() - 1)) {
                // cout << "VY[i].second: " << VY[i].second << '\n';
                minY[VY[i].second] = mm;
            }
            mm--;
        }
        
        // cout << "\nCount minY:\n";
        // FOR(i,1,m+1)
        //     cout << minY[i] << " ";
        // cout << '\n';

        ll ans = 0;
        ll _min = INT_MAX;
        int x, y;
        FORE(it,E)
        {
            pair<int, int> tmp = it->second;
            ll sum = X[tmp.first] + Y[tmp.second];
            ll _m = minX[MX[tmp.first]] + minY[MY[tmp.second]];
            // cout  << "tmp.first: " << tmp.first << "    tmp.second: " << tmp.second << '\n';
            // cout  << "MX[tmp.first] " << MX[tmp.first] << "    tmp.second: " << tmp.second << '\n';
            // cout  << "tmp.first: " << tmp.first << "    tmp.second: " << tmp.second << '\n';
            if (_min >= _m) {
                _min = _m;
                x = tmp.first;
                y = tmp.second;
            }
            ans += sum;
        }

        ll ans2 = ans - _min;

        cout << ans << " " << ans - _min << '\n';
        // cout << x << " " << y << '\n';
    }

    return 0;
}