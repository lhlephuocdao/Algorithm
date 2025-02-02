#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n; cin >> n;
    string S; cin >> S;
    if (S[0] == '1' || S[n-1] == '1') {
        cout << "YES\n";
        return;
    }

    for (int i = 1; i < n-2; i++)
    {
        if (S[i] == '1' && S[i+1] == '1') {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}