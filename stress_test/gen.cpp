#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define ll long long
#define pii pair<int, int>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b)
{
    if (a > b) return 0;
    return a + rng() % (b - a + 1);
}

// !!! change shuffle for BETTER TREE
void genTree(int n) {
    bool shuffle = true;

    cout << n << '\n';
    int type = random(1, 4);  // 1: Random, 2: Start, 3: Line, 4: Binary tree
    vector<pair<int, int>> edges;
    for (int v = 2; v <= n; v++) {
        int u;
        switch (type) {
            case 1:
                u = random(1, v - 1);
                break;
            case 2:
                u = 1;
                break;
            case 3:
                u = v - 1;
                break;
            case 4:
                u = v / 2;
                break;
        }
        edges.push_back({u, v});
    }
    if (!shuffle) {
        for (auto e : edges) {
            cout << e.first << " " << e.second << '\n';
        }
        return;
    }

    // rename vertices and random order of edges
    vector<int> perm(n + 1);
    for (int i = 1; i <= n; i++) perm[i] = i;
    random_shuffle(edges.begin(), edges.end());
    
    for (auto e : edges) {
        int u = e.first, v = e.second;
        if (random(0, 1)) {
            swap(u, v);
        }
        // int w = random(1, 100);
        cout << perm[u] << " " << perm[v] << '\n';
    }
}

void generateRandomTree(int n) {
    vector<int> parents(n + 1);
    parents[1] = 0; // Root node has no parent
    
    for (int i = 2; i <= n; i++) {
        parents[i] = rand() % (i - 1) + 1; // Random parent from previous nodes
    }
    
    // random_shuffle(parents.begin()+1, parents.end());

    // Print the tree structure
    for (int i = 1; i <= n; i++) {
        cout << parents[i] << " ";
    }
    cout << "\n";
}


int32_t main()
{
    fastio;

    int n = random(1, 10);
    cout << n << '\n';
    for (int i = 1; i <= n; i++)
        cout << random(0, n) << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++)
        cout << random(0, n) << ' ';

    return 0;
}