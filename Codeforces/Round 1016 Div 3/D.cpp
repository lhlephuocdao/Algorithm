#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
const int mod = 998244353;
#define sc second
#define fi first
#define pii pair<int,int>

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

pii back(int x1, int y1, int x2, int y2, int mi, int ma, int d) {
    if (x1==x2 && y1==y2) return {x1,y1};
    int x = (ma-mi+1)/4;
    int len = (x2 - x1 + 1) / 2;
    int diff = d-mi+1;
    if (diff <= x) {
        return back(x1,y1,x1+len-1,y1+len-1,mi,mi+x-1,d);
    } else if (diff <= 2*x) {
        return back(x1+len,y1+len,x2,y2,mi+x,mi+2*x-1,d);
    } else if (diff<=3*x) {
        return back(x1+len,y1,x2,y1+len-1,mi+2*x,mi+3*x-1,d);
    } else {
        return back(x1,y1+len,x1+len-1,y2,mi+3*x,mi+4*x-1,d);
    }
}

int back2(int x1, int y1, int x2, int y2, int mi, int ma, int x, int y) {
    if (mi == ma) return ma;
    int len = (x2-x1+1)/2;
    int diff_val = (ma-mi+1)/4;
    if (x <= x1+len-1 && y <= y1+len-1) {
        return back2(x1,y1,x1+len-1,y1+len-1,mi,mi+diff_val-1,x,y);
    } else if (x >=x1+len && y >= y1+len) {
        return back2(x1+len,y1+len,x2,y2,mi+diff_val,mi+2*diff_val-1,x,y);
    } else if (x >= x1+len && y <= y1+len-1) {
        return back2(x1+len,y1,x2,y1+len-1,mi+2*diff_val,mi+3*diff_val-1,x,y);
    } else {
        return back2(x1,y1+len,x1+len-1,y2,mi+3*diff_val,mi+4*diff_val-1,x,y);
    }
}

int32_t main()
{
    fastio;

    int t = 1; cin >> t;
    while (t--)
    {
        int n,q;
        cin >> n >> q;
        string a = "->";
        string b = "<-";
        while (q--) {
            string s;
            cin >> s;
            int max_ = (1LL<<(2*n));
            if (s == a) {
                int x,y;
                cin >> x >> y;
                cout << back2(1,1,2*n,2*n,1,max_,x,y) << '\n';
            } else {
                int d;
                cin >> d;
                pii ans = back(1,1,2*n,2*n,1,max_,d);
                cout << ans.first << ' ' << ans.second << '\n';
            }
        }
    }
    return 0;
}