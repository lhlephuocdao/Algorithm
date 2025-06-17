#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 3e5 + 7;
const int maxp = 1e9 + 7;
int n,p,k;
unordered_map<int, int> cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int c = (((1ll*x*x%p) *x%p)*x%p - 1ll*k*x%p + p)%p;
        cnt[c]++;
    }

    ll ans = 0;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        int c = it->second;
        ans += c*(c-1)/2;
    }

    cout << ans;

    return 0;
}