#include <iostream>
#include <vector>

using namespace std;

// Initialize the segment tree and lazy array
void build_tree(vector<int>& arr, vector<int>& tree, vector<int>& lazy, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build_tree(arr, tree, lazy, 2 * node, start, mid);
    build_tree(arr, tree, lazy, 2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right) {
    // Propagate lazy updates if necessary
    if (lazy[node] != 0) {
        tree[node] += lazy[node] * (end - start + 1);
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > right || end < left) {
        return 0; // Out of range
    }
    if (start >= left && end <= right) {
        return tree[node]; // Node is fully within the range
    }

    int mid = (start + end) / 2;
    int left_sum = query(tree, lazy, 2 * node, start, mid, left, right);
    int right_sum = query(tree, lazy, 2 * node + 1, mid + 1, end, left, right);
    return left_sum + right_sum;
}

void update(vector<int>& tree, vector<int>& lazy, int node, int start, int end, int left, int right, int value) {
    // Propagate lazy updates if necessary
    if (lazy[node] != 0) {
        tree[node] += lazy[node] * (end - start + 1);
        if (start != end) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > right || end < left) {
        return;
    }

    if (start >= left && end <= right) {
        tree[node] += value * (end - start + 1);
        if (start != end) {
            lazy[2 * node] += value;
            lazy[2 * node + 1] += value;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(tree, lazy, 2 * node, start, mid, left, right, value);
    update(tree, lazy, 2 * node + 1, mid + 1, end, left, right, value);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int n = arr.size();
    vector<int> tree(4 * n);
    vector<int> lazy(4 * n, 0);
    build_tree(arr, tree, lazy, 1, 0, n - 1);

    // Insert an element at index 2 (0-based indexing)
    int insert_index = 2;
    int insert_value = 4;
    update(tree, lazy, 1, 0, n - 1, insert_index, insert_index, insert_value);

    // Query the sum of elements in the range [1, 3] (inclusive)
    int left_range = 1;
    int right_range = 3;
    int result = query(tree, lazy, 1, 0, n - 1, left_range, right_range);
    cout << "Sum of elements in the range [1, 3]: " << result << endl;

    return 0;
}
