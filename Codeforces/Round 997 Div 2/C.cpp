#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> calculate(int n) {
    vector<int> s(n);
    int mid = (n+1)/2;
    for (int i = 0; i < n; ++i) {
        s[i] = (i+1)%mid;
        if (s[i] == 0) s[i] = mid;
    }
    return s;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    vector<int> ans_6 = {1,1,2,3,1,2};
    while (t--)
    {
        int n; cin >> n;

        vector<int> result;
        if (n == 6) result = ans_6;
        else result = calculate(n);

        for (int i = 0; i < n; ++i)
            cout << result[i] << " ";
        cout << '\n';
    }
    return 0;
}