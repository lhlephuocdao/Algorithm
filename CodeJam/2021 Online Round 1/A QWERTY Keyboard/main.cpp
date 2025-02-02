#include <bits/stdc++.h>

using namespace std;

const int maxv = 26;;
int graph[maxv][maxv];

int index(char c)
{
    return c - 'A';
}

void calc(vector<vector<int>> mp)
{
    for (int i = 0; i < maxv; i++)
    {
        vector<int> v = mp[i];
        for (auto j : v) graph[i][j] = 2;
    }
}

void init()
{
    for (int i = 0; i < maxv; i++)
        for (int j = 0; j < maxv; j++)
            graph[i][j] = INT_MAX;


    vector<vector<int>> mp(26);

    mp[index('Q')] = {index('A'), index('W')};
    mp[index('W')] = {index('Q'), index('A'), index('S'), index('E')};
    mp[index('E')] = {index('W'), index('S'), index('D'), index('R')};
    mp[index('R')] = {index('E'), index('D'), index('F'), index('T')};
    mp[index('T')] = {index('R'), index('F'), index('G'), index('Y')};
    mp[index('Y')] = {index('T'), index('G'), index('H'), index('U')};
    mp[index('U')] = {index('Y'), index('H'), index('J'), index('I')};
    mp[index('I')] = {index('U'), index('J'), index('K'), index('O')};
    mp[index('O')] = {index('I'), index('K'), index('L'), index('P')};
    mp[index('P')] = {index('O'), index('L')};

    mp[index('A')] = {index('Q'), index('W'), index('S'), index('Z')};
    mp[index('S')] = {index('W'), index('E'), index('D'), index('X'), index('Z'), index('A')};
    mp[index('D')] = {index('E'), index('R'), index('F'), index('C'), index('X'), index('S')};
    mp[index('F')] = {index('R'), index('T'), index('G'), index('V'), index('C'), index('D')};
    mp[index('G')] = {index('T'), index('Y'), index('H'), index('B'), index('V'), index('F')};
    mp[index('H')] = {index('Y'), index('U'), index('J'), index('N'), index('B'), index('G')};
    mp[index('J')] = {index('U'), index('I'), index('K'), index('M'), index('N'), index('H')};
    mp[index('K')] = {index('I'), index('O'), index('L'),             index('M'), index('J')};
    mp[index('L')] = {index('O'), index('P'), index('K')};

    mp[index('Z')] = {index('A'), index('S'), index('X')};
    mp[index('X')] = {index('Z'), index('S'), index('D'), index('C')};
    mp[index('C')] = {index('X'), index('D'), index('F'), index('V')};
    mp[index('V')] = {index('C'), index('F'), index('G'), index('B')};
    mp[index('B')] = {index('V'), index('G'), index('H'), index('N')};
    mp[index('N')] = {index('B'), index('H'), index('J'), index('M')};
    mp[index('M')] = {index('N'), index('J'), index('K')};

    calc(mp);
}

int minDistance(vector<int>& dist, vector<bool>& unvisited) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < maxv; ++v) {
        if (unvisited[v] == true && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

vector<int> dijkstra(int s, int e)
{
    vector<int> d(maxv, INT_MAX);
    vector<bool> unvisited(maxv, true);

    d[s] = 0;
    for (int i = 0; i < maxv - 1; i++) {
        int u = minDistance(d, unvisited);

        if (d[u] == INT_MAX) break;

        unvisited[u] = false;

        for (int v = 0; v < maxv; v++) {
            if (unvisited[v] == true && graph[u][v] != INT_MAX && d[u] + graph[u][v] < d[v]) {
                d[v] = d[u] + graph[u][v];
            }
        }

        if (u == e) break;
    }
    return d;
}

void solve()
{
    string s; cin >> s;
    int ans = 0, n = s.length();

    ans += n;
    for (int i = 0; i < n-1; i++)
    {
        int u = s[i] - 'A';
        int v = s[i+1] - 'A';

        if (u == v) continue;
        else {
            //calculate the min path between u and v
            vector<int> ret = dijkstra(u, v);
            ans += ret[v];
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}