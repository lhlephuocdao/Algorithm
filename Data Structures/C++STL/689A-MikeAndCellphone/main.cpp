#include <bits/stdc++.h>

using namespace std;

int n, a[10];
string s;
map<int, pair<int, int>> m;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int check(int index, int x)
{
    pair<int, int> p = m[x];
    int new_x = p.first + dx[index];
    int new_y = p.second + dy[index];

    if (new_y <= 0 || new_y >= 4) return 0;
    if (new_x <= 0 || new_x >= 5 || (new_x == 4 && new_y == 1) || (new_x == 4 && new_y == 3)) return 0;

    return 1;
}

bool solve()
{
    for (int i = 0; i < 4; i++)
    {
        int ret = 1;
        for (int j = 0; j < n; j++)
        {
            ret *= check(i, a[j]);
        }
        if (ret == 1) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    m[1] = {1, 1};
    m[2] = {1, 2};
    m[3] = {1, 3};
    m[4] = {2, 1};
    m[5] = {2, 2};
    m[6] = {2, 3};
    m[7] = {3, 1};
    m[8] = {3, 2};
    m[9] = {3, 3};
    m[0] = {4, 2};

    cin >> n >> s;

    for (int i = 0; i < s.length(); i++)
    {
        a[i] = s[i] - '0';
    }

    if (solve()) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}