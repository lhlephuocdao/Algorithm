#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
#define ll long long

const int maxn = 1007;
int n, seed, a, b;
int graph[maxn][maxn];
ll check[maxn][maxn];

void DFS(int u, vector<bool>& visited)
{
    visited[u] = true;
    for (int v = 0; v < n; v++)
        if (graph[u][v] == 1 && visited[v] == false)
            DFS(v, visited);
}

bool isGraphConnected()
{
    vector<bool> visited(n, false);
    DFS(0, visited);
    for (int i = 0; i < n; i++)
        if (visited[i] == false) return false;
    return true;
}

void solve()
{
    cin >> n >> seed >> a >> b;
    auto start = high_resolution_clock::now();
    ll pre_e = 0;
    bool first = true;
    memset(graph, 0, sizeof(graph));
    memset(check, 0, sizeof(check));

    int m = 0;
    while (true)
    {
        m++;
        ll e, x, y;
        if (first) {
            e = seed % (n*n);
            first = false;
        } else {
            e = (pre_e*a + b)%(n*n);
        }

        x = e/n;
        y = e%n;
        pre_e = e;

        if (x != y && graph[x][y] == 0)
        {
            graph[x][y] = 1;
            graph[y][x] = 1;
            check[x][y] = e;

            //Kiem tra chu trinh lien thong hay khong
            if (isGraphConnected() == true) {
                cout << m << '\n';
                break;
            }
        } else if (graph[x][y] == 1 && check[x][y] == e) {
            cout << 0 << '\n';
            break;
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
     cout << "Time taken by function: "
         << duration.count() << " milliseconds" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}