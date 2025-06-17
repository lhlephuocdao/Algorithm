#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int mod = 1e9 + 7;
const int MAX_N = 20;

int n,m;
vector<unordered_set<int>> v(MAX_N);
ll _memory[MAX_N][1<<MAX_N]; // for memoization
int c[MAX_N][MAX_N];

ll solve(int from, int toFlag)
{
    ll &memo = _memory[from][toFlag];
    if (memo != 0) {
        return memo;
    }

    if (__builtin_popcount(toFlag) == 1 && __builtin_ctz(toFlag) == n-1)
    {
        if (std::find(v[from].begin(), v[from].end(), n-1) != v[from].end()) {
            memo = c[from][n-1];
        }
        return memo;
    }

    for (auto x : v[from]) {
        if (!(toFlag & (1<<x)) || x == n-1) continue; // city x is already visited or city x is the last city

        memo += (c[from][x] * solve(x, toFlag & ~(1<<x)))%mod;
        memo %= mod;
    }

    return memo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    memset(_memory, 0, sizeof(_memory));
    memset(c, 0, sizeof(c));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        v[a].insert(b);
        c[a][b]++;
    }

    int allFlag = (1<<n)-1; //0x1111
    cout << solve(0, allFlag & ~(1<<0));

    return 0;
}
