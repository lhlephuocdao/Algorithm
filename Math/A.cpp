#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    
    vector<int> ans = factorize(N);
    ans.push_back(0);
    int maxn = 1e6 + 7;
    vector<int> pre;
    pre.resize(maxn);
    
    for (int i = 1; i <= maxn; i++)
        pre[i] = pre[i-1] + i;

    int count = 0, prev = ans[0];
    int ret = 0;
    for (int i = 0; i < ans.size(); i++) {
        int x = ans[i];
        if (x == prev) count++;
        else {
            int c = lower_bound(pre.begin(), pre.end(), count) - pre.begin();
            auto itr = std::find(pre.begin(), pre.end(), count);
            if (itr == pre.end()) c--;
            ret += c;
            prev = x;
            count = 1;
        }
    }

    cout << ret << '\n';

    return 0;
}