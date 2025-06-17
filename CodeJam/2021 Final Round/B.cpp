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
const int maxn = 1e7;
int fact[maxn + 1];

int32_t main()
{
    fastio;

    fact[0] = 1;
    for (int i = 1; i <= maxn; i++)
        fact[i] = 1LL * fact[i - 1] * i % mod;

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n,m,x,C,D;
        cin >> n >> m >> x >> C >> D;
        vector<int> A(n), B(m);
        for (auto& i : A) cin >> i;
        for (auto& i : B) cin >> i;
        /*
            Có n con đường ở phía đông A[1], A[2], ... A[n],
            m con đường ở phía tây B[1], B[2], ... , B[m]
            Mỗi con đường đều xuất phát và kết thúc tại 1 vị trí.
            Có 1 cây cầu có độ dài x nối phía đông và tây
            Albert cần sử dụng các Paths có độ dài nằm trong đoạn [C,D]
            Mỗi Paths tuân theo quy tắc:
            - Paths phải bắt đầu từ 1 phía -> đi qua cầu
             -> đi qua 1 con đường phía bên kia -> đi qua cầu -> ...
            - Không thể kết thúc Paths ở trên cầu

            Tìm số con đường thỏa mãn
        */

        function<vector<vector<int>>(vector<int>&)> calc = [&](vector<int>& arr){
            int sz = arr.size();
            // ans[i] : gồm vector các sum mà có số con đường tạo thành nó là i
            vector<vector<int>> ans(sz+1);
            for (int s = 1; s < (1<<sz); s++) {
                int cnt = __builtin_popcount(s);
                int sum = 0;
                for (int i = 0; i < sz; i++) {
                    if (s & (1<<i))
                        sum += arr[i]; 
                }
                ans[cnt].push_back(sum);
            }
            return ans;
        };

        vector<vector<int>> SA = calc(A);
        for (auto& x : SA) sort(all(x));
        assert(SA.size() == n+1);
        vector<vector<int>> SB = calc(B);
        for (auto& x : SB) sort(all(x));
        assert(SB.size() == m+1);


        // function<void(vector<vector<int>>&)> debug = [&](vector<vector<int>>& arr){
        //     for (int i = 1; i < arr.size(); i++) {
        //         cout << "count = " << i << " : ";
        //         for (auto x : arr[i]) cout << x << ' ';
        //         cout << '\n'; 
        //     }
        // };
        // cout << "SA : \n";
        // debug(SA);
        // cout << "SB : \n";
        // debug(SB);

        int ans = 0;
        for (auto i : A) if (C<=i && i<=D) ans++;
        for (auto i : B) if (C<=i && i<=D) ans++;

        for (int i = 1; i <= n; i++) {
            int cnt1 = i;
            vector<int>& sumA = SA[i];

            for (int j = i-1; j <= i+1; j++) {
                if (j == 0 || j > m) continue;
                int cnt2 = j;
                vector<int>& sumB = SB[j];
                int bridges = x*(cnt1 + cnt2 - 1);
                for (auto sa : sumA) {
                    // C <= sa + sb + brigdes <= D
                    // sb >= C - sa - bridges
                    // sb <= D - sa - bridges
                    int lower = max(C - sa - bridges, 1ll);
                    int upper = D - sa - bridges;
                    auto lo = lower_bound(sumB.begin(), sumB.end(), C - sa - bridges);
                    auto hi = upper_bound(sumB.begin(), sumB.end(), D - sa - bridges);
                    if (lo != sumB.end() && hi != sumB.begin()) {
                        hi--;
                        int dis = hi - lo + 1;
                        int tmp = fact[cnt1] * fact[cnt2] % mod * dis % mod;
                        if (j == i) tmp = (tmp*2)%mod;
                        ans += tmp;
                        ans %= mod;
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}