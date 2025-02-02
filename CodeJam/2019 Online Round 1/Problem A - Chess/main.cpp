#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s; int a;
    cin >> s >> a;

    int sum = s[0] - 'A' + 1 + s[1] - '0';
    // 0: black, 1 : white
    int firstColor, secondColor;
    if (sum%2 == 0) firstColor = 0;
    else firstColor = 1;

    int m[2] = {1, 0};
    int nguyen = a/8;
    int du = a%8;

    if (du == 0 || du%2 != 0) secondColor = 1 - m[nguyen%2];
    else secondColor = m[nguyen%2];

    if (firstColor == secondColor) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}