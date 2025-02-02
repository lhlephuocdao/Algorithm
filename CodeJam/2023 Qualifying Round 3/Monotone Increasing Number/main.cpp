#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll MAXNUM = ll(1e5);
const ll MOD = ll(1e9) + 7;
 
vector<ll> cand;
vector<ll> prefix;
 
void preprocess() {
    cand.clear();
    cand.push_back(0);
 
    queue<ll> q;
    for (int i = 1; i < 10; ++i) q.push(i);
 
    while (!q.empty()) {
        ll t = q.front();
        q.pop();
 
        cand.push_back(t);
        int last_num = t % 10;
        for (int i = last_num; i < 10; ++i) {
            if (t > (MAXNUM - i) / 10) continue;
            q.push(t * 10 + i);
            cout << t*10+1 << " ";
        }
    }
    cout << '\n';
    cand.push_back(ll(1e18) + 1);
 
    prefix.clear();
    prefix.resize(int(cand.size()));
    for (int i = 1; i < int(cand.size()); ++i) {
        prefix[i] = prefix[i - 1];
        prefix[i] +=
            (((cand[i] - cand[i - 1]) % MOD) * (cand[i - 1] % MOD)) % MOD;
        prefix[i] %= MOD;
    }
}
 
void solve(int tc) {
    ll N, M;
    cin >> N >> M;
 
    ll ans = 0;
    int lo = lower_bound(cand.begin(), cand.end(), N) - cand.begin();
    int hi = lower_bound(cand.begin(), cand.end(), M) - cand.begin();
 
    if (hi == 0) {
        cout << 0 << '\n';
        return;
    }
 
    if (lo == hi) {
        ans += ((M - N) % MOD) * (cand[hi - 1] % MOD);
        ans %= MOD;
        if (cand[hi] == M) {
            ans += M % MOD;
        } else {
            ans += cand[hi - 1] % MOD;
        }
        ans %= MOD;
    } else {
        ans += (prefix[hi - 1] - prefix[lo] + MOD) % MOD;
 
        if (cand[lo] > N) {
            ans += ((cand[lo] - N) % MOD) * (cand[lo - 1] % MOD);
            ans %= MOD;
        }
 
        ans += ((M - cand[hi - 1]) % MOD) * ((cand[hi - 1]) % MOD);
        ans %= MOD;
        if (cand[hi] == M) {
            ans += M % MOD;
        } else {
            ans += cand[hi - 1] % MOD;
        }
        ans %= MOD;
    }
    cout << ans << '\n';
}
 
int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    preprocess();
    int tcs = 1;
    cin >> tcs;
    int tc = 1;
    while (tc <= tcs) solve(tc++);
}