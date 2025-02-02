#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 7;
map<pair<int, int>, int> m;

pair<int, int> make(int d, int k)
{
    if (d == 0 || k == 0) return {0, 0};
    if (d == 1 || k == 1) return {d, k};

    int nd = d, nk = k;
    int di = __gcd(d, k);
    nd /= di;
    nk /= di;

    return {nd, nk};
}

void solve()
{
    m.clear();
    int n;
    string s;
    cin >> n >> s;
    int nd = 0, nk = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'D') nd++;
        else nk++;
        int n_d, n_k;
        std::tie(n_d, n_k) = make(nd, nk);
        // cout << "n_d: " << n_d << " n_k: " << n_k << '\n';
        cout << ++m[{n_d, n_k}] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}