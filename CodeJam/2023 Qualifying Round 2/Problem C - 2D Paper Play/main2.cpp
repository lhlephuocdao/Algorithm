#include <bits/stdc++.h>

using namespace std;

struct Rect {
    int w, h;
    bool operator<(const Rect& other) const {
        if (w == other.w) return h > other.h;
        return w > other.w;
    }
};

vector<Rect> rects; // Mảng chứa các hình chữ nhật

struct Node {
    int w, h;
    Node *left, *right;
    Node(int w, int h) : w(w), h(h), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int w, int h) {
    if (!root) return new Node(w, h);
    if (w <= root->w) {
        root->left = insert(root->left, w, h);
    } else {
        root->right = insert(root->right, w, h);
    }
    return root;
}

Node* find(Node* root, int w, int h) {
    if (!root) return nullptr;
    if (w <= root->w && h <= root->h) {
        Node* left = find(root->left, w, h);
       
    if (left) return left;
    return root;
    }
    if (w > root->w) {
        return find(root->right, w, h);
    }
    return nullptr;
}

vector<int> count_covered(const vector<int>& X, const vector<int>& Y, const vector<int>& W, const vector<int>& H) {
    int n = X.size();
    int m = W.size();
    vector<int> C(n, 0);
    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++) {
        points[i] = {X[i], Y[i]};
    }

    sort(rects.begin(), rects.end());
    cout << "rects after sorting:\n";
    for (int i = 0; i < rects.size(); i++)
        cout << rects[i].w << " " << rects[i].h << '\n';

    sort(points.begin(), points.end());
    cout << "points after sorting:\n";
    for (int i = 0; i < points.size(); i++)
        cout << points[i].first << " " << points[i].second << '\n';

    Node* root = nullptr;
    int j = 0;

    for (auto itr : points) {
        int x = itr.first;
        cout << "x = " << x << '\n';
        int y = itr.second;
        cout << "y = " << y << '\n';

        while (j < m && W[j] >= x) {
            cout << "W[" << j << "]: " << W[j] << '\n';
            cout << "H[" << j << "]: " << H[j] << '\n';
            root = insert(root, W[j], H[j]);
            j++;
        }

        Node* node = find(root, x, y);
        if (node) {
            cout << "node not nullptr\n";
            C[lower_bound(points.begin(), points.end(), make_pair(x, y)) - points.begin()]++;
        }
    }

    return C;
}

int main()
{
    vector<int> X = {2,8,4,7,3}, Y = {2,3,3,4,5};
    rects = {{4,4}, {8,4}, {9,3}};
    vector<int> W = {9,8,4}, H = {3,4,4};

    vector<int> C = count_covered(X, Y, W, H);

    for (auto itr : C)
        cout << itr << " ";
    cout << '\n';

    cout << C[0] << '\n';

    return 0;
}

/*

Trong đó, `Rect` là một cấu trúc dữ liệu để lưu trữ thông tin về chiều rộng (width) và chiều cao (height) của một hình chữ nhật.
Các hình chữ nhật được sắp xếp theo chiều rộng giảm dần và chiều cao giảm dần.

`Node` là một cấu trúc dữ liệu để lưu trữ thông tin về chiều rộng và chiều cao của một nút trong cây nhị phân tìm kiếm. Hàm `insert` được sử dụng để thêm một nút mới vào cây.
Hàm `find` được sử dụng để tìm kiếm nút lớn nhất mà có chiều rộng nhỏ hơn hoặc bằng `w` và chiều cao nhỏ hơn hoặc bằng `h`.

Hàm `count_covered` được sử dụng để tính mảng `C[]`.
Đầu tiên, ta sắp xếp các hình chữ nhật và điểm theo thứ tự đã nêu ở trên. Sau đó, ta duyệt qua các điểm và tìm hình chữ nhật lớn nhất mà có thể bao phủ điểm đó bằng cách sử dụng cây nhị phân tìm kiếm. 
Nếu tìm thấy, ta tăng giá trị của `C(i)` lên 1. Cuối cùng, ta trả về mảng `C[]`.

Chúng ta có thể sử dụng thuật toán này để giải quyết bài toán với độ phức tạp thuật toán là O((N+M)logM).

*/