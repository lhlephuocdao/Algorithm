#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1007;
int N,X,Y, V[maxn];

void solve()
{
    cin >> N >> X >> Y;
    memset(V, 0, sizeof(0));
    for (int i = 0; i < N; i++) cin >> V[i];

    double  min_time = (double)INT_MAX;
    for (int i = 0; i < N-1; i++) {
        double t = (double)X/V[i];
        min_time = std::min(min_time, t);
    }

    double m_time = (double)X/V[N-1];
    if (m_time < min_time) {
        cout << 0 << '\n';
        return;
    }

    double z = (double)X - (double)V[N-1]*(min_time - 1);
    int Z = (int)z + 1;

    if (Z <= Y) cout << Z << '\n';
    else cout << -1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}