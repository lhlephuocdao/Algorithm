#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int INF = 1e18;

// directions: 0=up, 1=right, 2=down, 3=left
// 4=up-left, 5=down-right, 6=up-right, 7=down-left
int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug :
 *      - duplicated element
 *      - consecutive range: 1 2 3 4 5 ....
 * stress test
 */

int32_t main()
{
    fastio;

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        double epsilon = 1e-3;
        int n,x;
        cin >> n >> x;
        double p = 0;
        for (int i = 0; i < n; i++) {
            double c;
            cin >> c;
            p += c;
        }

        // cout << p << '\n';

        int minF = INF, maxF = -INF;

        // Calculate min F so that p + p*F/100 >= x
        // p*F/100 có dạng: x.xxyz... -> p*F = xxx hoặc xx(x+1) nếu có yz
        // 100*p + p*F >= 100*x
        // p*F >= 100*x - 100*p
        // F >= (100*x - 100*p)/p
        double a = (double)100*x - 100*p;
        double F = a/p;
        int j = F;

        function<bool(int)> check = [&](int rate) {
            double h = ceil(p * rate) / 100;

            if (abs(p+h-x) < epsilon) 
            {
                return true;
            } else if (p+h - x > 0) return true;
            else return false;
        };

        for (int i = max(0ll, j-2); i <= j+2; i++) {
            // i : sale tax
            // double tmp = p*i/100; // 12.992
            // int tax = (int)(tmp*100); // 1299
            // // 1299.2 * 1000 - 1299*1000
            // // 1299200 - 1299000
            // int diff = (int)(tmp*100*1000) - tax*1000;
            // if (diff > 0) tax++;
            // if ((int)(p*100) + tax >= x*100) {
            //     minF = min(minF, i);
            // }
            if (check(i)) minF = min(minF, i);
        }
        if (minF == INF) minF = 0;

        assert(minF >= 0 && minF <= 10000);
        cout << minF << ' ';

        // p + p*F/100 < x+1
        // p*100 + tax < (x+1)*100
        // p*F < (x+1)*100 - p*100
        // F < ((x+1)*100 - p*100)/p
        F = ((double)(x+1)*100 - p*100)/p;
        for (int i = max((int)F-2, 0ll); i <= (int)F+2; i++) {
            double tmp = p*i/100; // 12.345
            int tax = (int)(tmp*100); // 1234
            if ((int)(p*100) + tax < (x+1)*100) {
                maxF = max(i, maxF);
            }
        }
        assert(maxF >= 0 && maxF <= 10000);
        cout << maxF << '\n';
    } 

    return 0;
}