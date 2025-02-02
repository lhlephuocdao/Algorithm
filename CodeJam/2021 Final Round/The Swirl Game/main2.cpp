#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v;

vector<int> spiralOrder(vector<vector<int> >& matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;
 
    if (m == 0)
        return ans;
 
    vector<vector<bool> > seen(m, vector<bool>(n, false));
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
 
    int x = 0, y = 0, di = 0;
 
    // Iterate from 0 to m * n - 1
    for (int i = 0; i < m * n; i++) {
        ans.push_back(matrix[x][y]);
        // on normal geeksforgeeks ui page it is showing
        // 'ans.push_back(matrix[x])' which gets copied as
        // this only and gives error on compilation,
        seen[x][y] = true;
        int newX = x + dr[di];
        int newY = y + dc[di];
 
        if (0 <= newX && newX < m && 0 <= newY && newY < n
            && !seen[newX][newY]) {
            x = newX;
            y = newY;
        }
        else {
            di = (di + 1) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
    return ans;
}

string calc(int r, int c, bool clockwise)
{
    // cout << "calc with r: " << r << " c: " << c << '\n';
    string ans;
    vector<vector<bool>> mark(n, vector<bool>(n, false));
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };

    int x = r, y = c;
    int di;
    int step = clockwise ? 1 : 3;

    if ((r == 0 && c == 0 & clockwise) || (r==n-1 && c==0 && !clockwise)) di = 0;
    if ((r == 0 && c == n-1 && !clockwise) || (r==n-1 && c==n-1 && clockwise)) di = 2;
    if ((r == 0 && c == 0 && !clockwise) || (r==0 && c==n-1 && clockwise)) di = 1;
    if ((r == n-1 && c == 0 && clockwise) || (r==n-1 && c==n-1 && !clockwise)) di = 3;

    for (int i = 0; i < n * n; i++) {
        // cout << "i: " << i << " v[" << x << "][" << y << "]: " << v[x][y] << '\n';
        ans += v[x][y];
        // on normal geeksforgeeks ui page it is showing
        // 'ans.push_back(matrix[x])' which gets copied as
        // this only and gives error on compilation,
        mark[x][y] = true;
        int newX = x + dr[di];
        int newY = y + dc[di];
 
        if (0 <= newX && newX < n && 0 <= newY && newY < n
            && !mark[newX][newY]) {
            x = newX;
            y = newY;
        }
        else {
            di = (di + step) % 4;
            x += dr[di];
            y += dc[di];
        }
    }
    return ans;
}

void solve()
{
    cin >> n;
    v.clear();
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<string> ret;
    ret.push_back(calc(0, 0, true));
    ret.push_back(calc(0, 0, false));
    ret.push_back(calc(0, n-1, true));
    ret.push_back(calc(0, n-1, false));
    ret.push_back(calc(n-1, n-1, true));
    ret.push_back(calc(n-1, n-1, false));
    ret.push_back(calc(n-1, 0, true));
    ret.push_back(calc(n-1, 0, false));

    sort(ret.begin(), ret.end());

    cout << ret.back() << " " << ret.front() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

// LLGLLGLGLLEEGLEGGGGEGGGLL