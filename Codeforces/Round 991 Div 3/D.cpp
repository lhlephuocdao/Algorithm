#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s; cin >> s;
    int n = s.length();
    stack<int> st, st2;
    for (int i = 0; i < n; i++) {
        int a = s[i] - '0';
        while (!st.empty() && st.top() < a-1) {
            st2.push(st.top());
            st.pop();
            a--;
        }

        st.push(a);

        while (!st2.empty()) {
            st.push(st2.top());
            st2.pop();
        }
    }

    vector<int> ans(n);
    int idx = n-1;
    while (!st.empty() && idx >= 0) {
        ans[idx] = st.top();
        st.pop();
        idx--;
    }
    for (auto x : ans) cout << x;
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}