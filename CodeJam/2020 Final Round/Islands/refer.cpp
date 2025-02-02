#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Union-Find Data Structure (Disjoint Set)
class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // Path compression
        }
        return parent[u];
    }

    bool unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
            return true;
        }
        return false;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    
    while (T--) {
        int N, Seed, A, B;
        cin >> N >> Seed >> A >> B;

        UnionFind uf(N);
        unordered_set<long long> existingEdges;
        long long E = Seed % (N * N);
        int day = 0;

        while (true) {
            day++;
            int X = E / N;
            int Y = E % N;

            if (X != Y) {
                long long edge = E;
                if (existingEdges.find(edge) == existingEdges.end()) {
                    existingEdges.insert(edge);
                    uf.unite(X, Y);
                }
            }

            // Check if all islands are connected
            bool allConnected = true;
            int root = uf.find(0);
            for (int i = 1; i < N; ++i) {
                if (uf.find(i) != root) {
                    allConnected = false;
                    break;
                }
            }

            if (allConnected) {
                cout << day << '\n';
                break;
            }

            // Generate next E value
            E = (E * A + B) % (N * N);
            
            // If cycle detected (no new bridges added)
            if (day > N * (N - 1) / 2 + 1) {  // At most N*(N-1)/2 edges in a complete graph
                cout << 0 << '\n';
                break;
            }
        }
    }

    return 0;
}
