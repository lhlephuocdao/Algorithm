#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> sub_gcd[n];
    /*
    Key is gcd,
    Value is the largest length such that gcd(a[i - len], ..., a[i]) equals to key.
    */
    sub_gcd[0][a[0]] = 0;
    for(int i = 1; i < n; i++)
    {
        sub_gcd[i][a[i]] = 0;
        for(auto it: sub_gcd[i - 1])
        {
            int new_gcd = __gcd(it.first, a[i]);
            sub_gcd[i][new_gcd] = max(sub_gcd[i][new_gcd], it.second + 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "i: " << i << '\n';
        for (auto it : sub_gcd[i])
            cout << it.first << " " << it.second << '\n';
    }

    return 0;
}
/*
    5
    4 6 9 24 27
*/