#include <bits/stdc++.h>
using namespace std;
#define int long long

void debug(vector<int>& a) {
    for (auto x : a) cout << x << ' ';
    cout << '\n';
}

struct node {
    int count;
    int index;
    bool is_row;
    unordered_set<int> id;
    node(int cnt, int idx, int flag) : count(cnt), index(idx), is_row(flag) {}
    static void debug(node& p) {
        string s = p.is_row ? "row: " : "column: ";
        cout << s << p.index << " " << p.count << " : ";
        for (auto x : p.id) cout << x << ' ';
        cout << '\n';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

   int t; cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int sum = 0;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        vector<int> sum_r(n, 0), sum_c(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                sum_r[i] += a[i][j];
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++)
                sum_c[j] += a[i][j];
        }
        debug(sum_r);
        debug(sum_c);
        int target = 0;
        for (auto x : sum_r) target += x;
        for (auto x : sum_c) target += x;
        // target /= n+m;
        target = 0;

        cout << "targter : " << target << '\n';

        int i = 0, j = 0;
        vector<node> row(n, {0,-1, true});
        vector<node> column(m, {0,-1, false});

        row[i].count++;
        row[i].index = i;
        row[i].id.insert(j);

        column[j].count++;
        column[j].index = j;
        column[j].id.insert(i);

        for (int is = 0; is < s.length(); is++)
        {
            if (s[is] == 'D') {
                i++;
            } else {
                j++;
            }
            row[i].count++;
            row[i].index = i;
            row[i].id.insert(j);

            column[j].count++;
            column[j].index = j;
            column[j].id.insert(i);
        }

        for (auto p : row) node::debug(p);
        for (auto p : column) node::debug(p);

        queue<node> q;
        for (auto& p : row) if (p.count == 1) {
            q.push(p);
            cout << "push row " << p.index << '\n';
        }
        for (auto& p : column) if (p.count == 1) {
            q.push(p);
            cout << "push column " << p.index << '\n';
        }

        int count = 0;
        while (!q.empty())
        {
            node p = q.front();
            q.pop();
            if (count == (n+m-1)) break;
            int x,y;
            if (p.is_row) {
                x = p.index;
                y = *p.id.begin();
                a[x][y] = target - sum_r[x];
                cout << "update a[" << x << "][" << y << "]: " << a[x][y] << '\n';
                sum_c[y] += a[x][y];
                cout << "update sum_c[" << y << "] : " << sum_c[y] << '\n';

                p.count--;
                p.id.erase(y);

                column[y].count--;
                column[y].id.erase(x);
                if (column[y].count == 1) {
                    q.push(column[y]);
                    cout << "push comlumn " << y << '\n';
                }
            } else {
                x = *p.id.begin();
                y = p.index;
                a[x][y] = target - sum_c[y];
                cout << "update a[" << x << "][" << y << "]: " << a[x][y] << '\n';
                sum_r[x] += a[x][y];
                cout << "update sum_r[" << x << "] : " << sum_r[x] << '\n';

                p.count--;
                p.id.erase(x);

                row[x].count--;
                row[x].id.erase(y);
                if (row[x].count == 1) {
                    q.push(row[x]);
                    cout << "push row " << x << '\n';
                }
            }
            count++;
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++)
                cout << a[x][y] << " ";
            cout << '\n';
        }
    }
}