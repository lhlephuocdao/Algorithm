#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
 
vector<ll> B, A, sumB, sumA;

void cal_combinations(vector<ll>& arr, vector<ll>& ans, vector<ll>& combination, int n, int k, int index) {
    if (k == 0) {
        ll ret = 0;
        for (int i = 0; i < combination.size(); i++) {
            ret += combination[i];
        }
        ans.push_back(ret);
        return;
    }
    for (int i = index; i < n; i++) {
        combination.push_back(arr[i]); // Chọn phần tử arr[i]
        cal_combinations(arr, ans, combination, n, k - 1, i + 1); // Tìm các phần tử kế tiếp
        combination.pop_back(); // Bỏ phần tử vừa chọn để chọn phần tử khác
    }
}

ll findNearest(vector<ll>& arr, int n, ll k) {
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == k) {
            return arr[mid];
        } else if (arr[mid] < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    // Tìm phần tử gần bằng k nhất
    if (r < 0) {
        return arr[0];
    } else if (l >= n) {
        return arr[n - 1];
    } else {
        if (k - arr[r] < arr[l] - k) {
            return arr[r];
        } else {
            return arr[l];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T;
    cin >> T;

    while (T--) {
        B.clear();
        A.clear();
        sumB.clear();
        sumA.clear();
        
        int n,m,k;
        cin >> n >> m >> k;
        FOR(i,0,n) {
            ll t;
            cin >> t;
            B.push_back(t);
        }

        FOR(i,0,m) {
            ll t;
            cin >> t;
            A.push_back(t);
        }

        vector<ll> comB;
        cal_combinations(B, sumB, comB, n, k, 0);

        vector<ll> comA;
        cal_combinations(A, sumA, comA, m, k, 0);

        sort(sumB.begin(), sumB.end());
        sort(sumA.begin(), sumA.end());

        ll min_diff = INT_MAX;
        ll max_diff = INT_MIN;

        FOR(i,0,sumB.size()) {
            ll ret = abs(findNearest(sumA, sumA.size(), sumB[i]) - sumB[i]);
            if (ret == 0) {
                min_diff = ret;
                break;
            } else {
                min_diff = (ret < min_diff) ? ret : min_diff;
            }
        }

        ll t1, t2;
        t1 = abs(sumB[0] - sumA.back());
        t2 = abs(sumA[0] - sumB.back());

        max_diff = (t1 > t2) ? t1 : t2;

        cout << min_diff << " " << max_diff << '\n';
    }

    return 0;
}