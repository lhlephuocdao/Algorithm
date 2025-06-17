#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<int>& a){
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a >> b;
        if (a%2 == 1)
            cout << "NO\n";
        else if (a == 0 && b%2==1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}