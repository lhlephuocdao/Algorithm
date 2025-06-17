#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long

void debug(vector<vector<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<set<int>>& a)
{
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}

void debug(vector<int>& a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << '\n';
}

void debug(map<int, vector<int>>& m)
{
    for (auto v : m) {
        cout << v.first << " : ";
        for (auto x : v.second)
            cout << x << ' ';
        cout << '\n';
    }
}

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& x : a)
        {
            cin >> x;
            m[x]++;
            pq.push(x);
        }

        bool check = true;
        for (auto it : m)
            if (it.second % 2 != 0) check = false;

        if (check) {
            cout << "Yes\n";
            continue;
        }

        int first = pq.top();
        pq.pop();

        int prev = pq.top();
        pq.pop();

        if (first != prev) {
            cout << "No\n";
            continue;
        }

        check = true;
        while (!pq.empty())
        {
            // cout << "prev: " << prev << '\n';
            while (!pq.empty() && pq.top() == prev) {
                pq.pop();
                // cout << "pop " << prev << " and push " << prev+1 << '\n';
                pq.push(prev+1);
            }

            if (!pq.empty())
            {
                prev = pq.top();
                pq.pop();
                // cout << "update prev: " << prev << '\n';
            } else break;


            if (pq.empty()) {
                check = false;
                break;
            }

            if (pq.top() == prev) {
                // cout << "pop " << pq.top() << '\n';
                pq.pop();
            }
            else {
                check = false;
                break;
            }
        }

        if (!pq.empty()) check = false;

        if (check)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}