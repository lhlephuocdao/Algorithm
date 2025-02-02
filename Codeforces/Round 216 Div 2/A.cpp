#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    int first = 0, second = 0;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if (a == 1) first++;
        else second++;
    }

    int need = 0;
    if (m >= first)
        m -= first;
    else {
        need = first - m;
        m = 0;
    }

    if (second >= m+k)
        need += second-(m+k);

    cout << need << '\n';

    return 0;
}