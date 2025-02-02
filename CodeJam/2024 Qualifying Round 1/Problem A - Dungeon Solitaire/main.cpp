#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;
const int MAX = 1e8;
int t,n,D[maxn], R[maxn];
string s;

long long solve()
{
    long double ans = 1;
    ans += D[n-1];
    bool flag = false;

    for (int i = n-2; i >= 0; i--)
    {
        if (s[i] == '+') {
            ans -= R[i];
            if (ans <= 0) ans = 1;
        }
        else {
            ans = ans / (double)R[i];
        } 
        ans += D[i];
    }

    long long res = (long long)ceil(ans);

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> D[i];
        cin >> s;
        for (int i = 0; i < n; i++)
            cin >> R[i];

        long long ans = solve();
        cout << ans << '\n';
    }

    return 0;
}