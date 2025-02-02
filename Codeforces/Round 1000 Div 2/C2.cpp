#include <bits/stdc++.h>
using namespace std;
#define int long long

void show(const vector<long long>& v) {
    long long n = v.size();
    for(long long i = 0; i < n; ++i) {
        std::cout << v[i] <<", ";
    }
    cout << "\n";
}

void show(const vector<pair<int, int>>& edge) {
    for (int i = 0; i < edge.size(); i++) {
        cout << edge[i].first << " " << edge[i].second << '\n';
    }
}

long long generate_random_int(long long min, long long max) {
    return min + (rand() % (long long)(max - min + 1));
}

int solve1(vector<pair<int, int>> edge, int n)
{
    vector<pair<int, int>> deg(n); // {cnt, index}
    for (int i = 0; i < n; i++)
        deg[i] = {0, i};

    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
            int u, v;
            u = edge[i].first;
            v = edge[i].second;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u].first++;
            deg[v].first++;
    }

        // cout << "solve 1\n";
        sort(deg.begin(), deg.end());
        // cout << "solve 2\n";

        int v1 = deg[n-1].second;
        deg.pop_back();
        // cout << "solve 3\n";
        sort(adj[v1].begin(), adj[v1].end());
        // cout << "solve 4\n";

        // cout << "solve 5\n";
        vector<bool> sub(n, false);
        // cout << "solve 6\n";
        for (auto x : adj[v1]) {
            sub[x] = true;
        // cout << "solve 7\n";
            adj[x].erase(find(adj[x].begin(), adj[x].end(), v1));
        }

        // cout << "solve 8\n";
        for (int i = 0; i < n-1; i++) {
            int v = deg[i].second;
        // cout << "solve 9\n";
            if (sub[v]) deg[i].first--;
        }

        // cout << "solve 10\n";
        sort(deg.begin(), deg.end());

        int j = n-2;
        int v2 = deg.back().second;
        // cout << "solve 11\n";

        vector<bool> mark(n, false);
        mark[v1] = true;
        mark[v2] = true;
        function<void(int, int)> dfs = [&](int p, int prev) {
            // cout << "mark " << p << " true\n";
            mark[p] = true;
            for (auto x : adj[p]) {
                if (mark[x] || x == prev) continue;
                dfs(x, p);
            }
        };

        // cout << "solve 12\n";
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (mark[i] == false) {
                ans++;
                dfs(i, -1);
            }
        }
        return ans;
}

int brute_force(vector<pair<int, int>> edge, int n)
{
    int ans = 0;
    for (int x = 0; x < n-1; x++)
    {
        for (int y = x+1; y < n; y++)
        {
            vector<vector<int>> adj(n);
            for (int i = 0; i < n-1; i++) {
                    int u, v;
                    u = edge[i].first;
                    v = edge[i].second;
                    u--; v--;
                    if (u == x || u == y || v == x || v == y) continue;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
            }

            vector<bool> mark(n, false);
            mark[x] = true;
            mark[y] = true;

            function<void(int, int)> dfs = [&](int p, int prev) {
                mark[p] = true;
                for (auto next : adj[p]) {
                    if (mark[next] || next == prev) continue;
                    dfs(next, p);
                }
            };

            int sol = 0;
            for (int i = 0; i < n; i++) {
                if (mark[i] == false) {
                    sol++;
                    dfs(i, -1);
                }
            }
            ans = max(ans, sol);
        }
    }
    return ans;
}

void stress_test(long long size, long long min, long long max) {
    int i = 1;
    while(1) {
        cout << "Iteration: " << i << "\n";
        long long n = generate_random_int(2, size);

        vector<pair<int, int>> edge;
        for (int i = 2; i <= n; ++i) {
        // Connect the current node to a random node among the already added nodes (1 to i-1)
        int parent = rand() % (i - 1) + 1;
        edge.push_back({parent, i});
    }
        // show(edge);
        // cout << "start\n";
        long long my_ans = solve1(edge, n);
        // cout << "my_ans: " << my_ans << '\n';
        long long brute = brute_force(edge, n);
        // cout << "brute: " << brute << '\n';

        if(my_ans != brute) {
            cout << "Fail: failed not less case\n";
            cout << "\n\narr: ";
            cout << "num=: " << n << "\n";
            show(edge);
            cout << "Approach: my ans: " << my_ans << "\n";
            cout << "Approach: brute: " << brute << "\n";
            break;
        }
        cout << "PASS\n";
        ++i;
    }
}

int32_t main() {
    srand(time(0));
    stress_test(50, 1, 10000000000000);
    return 0;
}