#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int n) {
    return (n / 15) * 3 + min(3ll, n % 15 + 1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}