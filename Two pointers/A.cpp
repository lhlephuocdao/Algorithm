#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    
    vector<pair<int, int>> a;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    
    sort(a.begin(), a.end());
    
    int i = 0, j = n-1;
    
    while (i < j)
    {
        int total = a[i].first + a[j].first;
        if (total == x) {
            cout << a[i].second << " " << a[j].second << '\n';
            return 0;
        } else if (total < x) i++;
        else j--;
    }
    
    cout << "IMPOSSIBLE\n";

    return 0;
}