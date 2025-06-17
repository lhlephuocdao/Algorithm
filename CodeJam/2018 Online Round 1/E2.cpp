#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

class Fenwick {
public:
    vector<int> tree;
    Fenwick() {
        tree.resize(MAX, 0);
    }

    int sum(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += tree[idx];
            idx -= (idx & -idx);
        }
        return ans;
    }

    void update(int idx, int num) {
        while (idx < MAX) {
            tree[idx] += num;
            idx += (idx & -idx);
        }
    }
};

vector<vector<int>> indices(const vector<int>& l) {
    Fenwick tree;
    map<int, vector<int>> adj;

    for (int i = 0; i < l.size(); ++i) {
        int v = l[i];
        adj[v].push_back(i - tree.sum(v - 1));
        tree.update(v, 1);
    }

    vector<vector<int>> result;
    for (auto& [_, vec] : adj) {
        result.push_back(vec);
    }
    return result;
}

map<int, int> cost(const map<int, int>& prev, const vector<int>& current) {
    map<int, int> result;

    auto acc = [&](int pos, int c) {
        if (!result.count(pos)) result[pos] = c;
        else result[pos] = min(result[pos], c);
    };

    for (auto& [prev_pos, prev_cost] : prev) {
        vector<int>::const_iterator it1 = lower_bound(current.begin(), current.end(), prev_pos);
        vector<int>::const_iterator it2 = upper_bound(current.begin(), current.end(), prev_pos);

        for (auto it : {it1, it2}) {
            int bi = distance(current.begin(), it);
            vector<int> left(current.begin(), current.begin() + bi);
            vector<int> right(current.begin() + bi, current.end());

            int leftmost = current.front();
            int rightmost = current.back();
            int rightmost_to_next = rightmost - (int)current.size() + 1;

            if (left.empty()) {
                int new_cost = prev_cost + (rightmost - prev_pos) + 1;
                acc(rightmost_to_next, new_cost);
                acc(rightmost_to_next - 1, new_cost);
            } else if (right.empty()) {
                int new_cost = prev_cost + (prev_pos - leftmost) + 1;
                acc(leftmost, new_cost);
                acc(leftmost - 1, new_cost);
            } else {
                // right -> left
                int to_right = (rightmost + 1 - prev_pos);
                int to_left = (rightmost + 1 - (int)right.size() - leftmost);
                int new_cost = prev_cost + to_right + to_left;
                acc(leftmost, new_cost);
                acc(leftmost - 1, new_cost);

                // left -> right
                to_left = (prev_pos + 1 - leftmost);
                to_right = (rightmost + 1 - (int)left.size() - leftmost);
                new_cost = prev_cost + to_left + to_right;
                acc(rightmost_to_next, new_cost);
                acc(rightmost_to_next - 1, new_cost);
            }
        }
    }
    return result;
}

int total_cost(const vector<vector<int>>& adj) {
    map<int, int> status;
    status[0] = 0;
    for (const auto& current : adj) {
        status = cost(status, current);
    }
    int ans = INT_MAX;
    for (auto& [_, v] : status) {
        ans = min(ans, v);
    }
    return ans;
}

void debug(vector<vector<int>>& a) {
    for (int i = 0; i < a.size(); i++)
    {
        cout << "adj[" << i << "]: ";
        for (auto y : a[i])
            cout << y << ' ';
        cout << '\n';
    }
}

int solve(const vector<int>& hs) {
    vector<vector<int>> adj = indices(hs);
    debug(adj);
    return total_cost(adj);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    cout << solve(H) << '\n';
    return 0;
}
