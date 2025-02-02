// created : 2022
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve(int tc) {
    int N;
    cin >> N;
 
    vector<int> A(N);
    for (int i=0; i<N; ++i) {
        cin >> A[i];
    }
 
    ll ans = 0;
 
    int lo = 0, hi = 0;
    while (hi < N) {
        if (lo == hi) {
            hi += 1;
            continue;
        }
 
        if (A[hi-1] < A[hi]) {
            if (hi-lo == 1 || A[hi-2] > A[hi-1]) {
                hi += 1;
            } else {
                ans += 1LL * (hi-lo) * (hi-lo-1) / 2;
                lo = hi-1;
            }
        } else if (A[hi-1] > A[hi]) {
            if (hi-lo == 1 || A[hi-2] < A[hi-1]) {
                hi += 1;
            } else {
                ans += 1LL * (hi-lo) * (hi-lo-1) / 2;
                lo = hi-1;
            }
        } else {  // A[hi-1]==A[hi]
            ans += 1LL * (hi-lo) * (hi-lo-1) / 2;
            lo = hi;
        }
    }
 
    ans += 1LL * (hi-lo) * (hi-lo-1) / 2;
    cout << ans << '\n';
}
 
int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int tcs = 1;
    cin >> tcs;
    int tc = 1;
    while (tc <= tcs) solve(tc++);
}