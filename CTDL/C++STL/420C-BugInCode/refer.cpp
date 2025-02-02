#include "bits/stdc++.h"

#ifndef LOCAL
#define debug(...) 86
#endif

#define fi first
#define se second 
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define i32 0x3f3f3f3f
#define i64 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll = long long;

template<class A, class B> bool chmax(A &a, B b) { return a < b && (a = b, true); }
template<class A, class B> bool chmin(A &a, B b) { return a > b && (a = b, true); }

void setIO(string s = "") {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(10);
 
    auto setIn = [&](string s) { freopen(s.c_str(), "r", stdin); };
    auto setOut = [&](string s) { freopen(s.c_str(), "w", stdout); };
    if (sz(s)) setIn(s+".in"), setOut(s+".out");
}    

const int maxN = 3e5 + 5;
vector<int> adj[maxN], val;
int N, P, deg[maxN], A[maxN], B[maxN];
ll ans;

int main() {
    setIO();
    
    cin >> N >> P;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i] >> B[i];
        adj[A[i]].emplace_back(i);
        adj[B[i]].emplace_back(i);
        deg[A[i]] += 1, deg[B[i]] += 1;
    }
    for (int i = 1; i <= N; ++i) {
        val.emplace_back(deg[i]);
    }
    sort(all(val));
    for (int i = 1; i <= N; ++i) {
        int need = P - deg[i];
        int cnt = N - (lower_bound(all(val), need) - val.begin());
        cout << "i: " << i << " deg[i]: " << deg[i] << " need: " << need << " cnt: " << cnt << '\n';
        if (deg[i] >= need) cnt -= 1;

        for (auto &j : adj[i]) {
            int v = A[j] + B[j] - i;
            cout << "j: " << j << " A[j]: " << A[j] << " B[j]: " << B[j] << " v: " << v << '\n';
            deg[v] -= 1;
            if (deg[v] == need - 1) cnt -= 1;
        }

        ans += cnt;
        cout << "ans: " << ans << "\n\n";


        for (auto &j : adj[i]) {
            int v = A[j] + B[j] - i;
            deg[v] += 1;
        }
    }
    ans /= 2;
    cout << ans << '\n';
}