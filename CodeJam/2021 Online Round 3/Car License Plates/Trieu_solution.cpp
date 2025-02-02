#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        //vector<string> a(n);
        string s;
        unordered_map<string, unordered_map<int,int>> data;
        for (int i=0; i<n; i++) {
            cin >> s;
            int c = 0;
            for(int j = 0; j < k; j++)
                if(s[j] >= 97) {
                    s[j] -= 32;
                    c++;
                }
            sort(s.begin(), s.end());
            data[s][c]++;
        }
        long long res = 0;
        for(auto it = data.begin(); it != data.end(); it++)
        {
            auto b = it -> second;
            for(auto it2 = b.begin(); it2 != b.end(); it2++)
                res += it2-> second * (it2 -> second - 1)/2;
        }
        cout << res << endl;
    }
    return 0;
}