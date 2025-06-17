#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<string, int>> v(10);
vector<int> cnt(10, 0);
long long ans = 0;

void backtrack(int pos, string& cur)
{
    if (pos == n) {
        for (int i = 0; i < m; i++) {
            if (cnt[i] != v[i].second)
                return;
        }
        ans++;
        return;
    }

    for (char i = '0'; i <= '1'; i++)
    {
        bool check1 = false, check2 = false;
        int mark = m;
        for (int j = 0; j < m; j++)
        {
            string s = v[j].first;
            int c = v[j].second;
            if (s[pos] == i) cnt[j]++;
            if (cnt[j] > c) {
                check1 = true;
                mark = j+1;
                break;
            }

            if (cnt[j] + (n-1-pos) < c) {
                if (s[pos] == i) check2 = true;
                else check1 = true;
                mark = j+1;
                break;
            }
        }

        if (check1 || check2) {
            for (int j = 0; j < mark; j++)
            {
                string s = v[j].first;
                int c = v[j].second;
                if (s[pos] == i) cnt[j]--;
            }
        }
        if (check1) continue;
        if (check2) return;

        cur.push_back(i);
        backtrack(pos+1, cur);
        cur.pop_back();
        for (int j = 0; j < mark; j++)
        {
            string s = v[j].first;
            int c = v[j].second;
            if (s[pos] == i) cnt[j]--;
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
    }

    string s = "";
    backtrack(0, s);
    cout << ans << '\n';

    return 0;
}
