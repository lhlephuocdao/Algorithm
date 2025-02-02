#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int l, r, cnt;
    Node *left, *right;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->cnt = 0;

        if (l < r) {
            int mid = (l + r) / 2;
            left = new Node(l, mid);
            right = new Node(mid + 1, r);
        }
    }

    void update(int x) {
        cnt++;

        if (l < r) {
            int mid = (l + r) / 2;

            if (x <= mid) {
                left->update(x);
            } else {
                right->update(x);
            }
        }
    }

    int query(int x, int y) {
        if (x <= l && r <= y) {
            return cnt;
        } else if (y < l || x > r)
            return 0;
        else {
            int res = 0;
            int mid = (l + r) / 2;

            if (x <= mid) {
                res += left->query(x, y);
            }

            if (y > mid) {
                res += right->query(x, y);
            }

            return res;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<pair<int, int>> rects(m);
    for (int i = 0; i < m; i++) {
        cin >> rects[i].first >> rects[i].second;
    }

    sort(rects.begin(), rects.end());

    Node *root = new Node(1, 2*m);
    
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        cout << "x[" << i << "]: " << x[i] << '\n';
        int pos = lower_bound(rects.begin(), rects.end(), make_pair(x[i], 0)) - rects.begin();
        cout << "pos: " << pos << '\n';
    
        for (int j = pos; j < m; j++) {
            if (rects[j].first >= x[i] && rects[j].second >= y[i]) {
                ans[i] = root->query(rects[j].first, 2*m);
                cout << "after query: ans[" << i << "]: " << ans[i] << '\n';
                break;
            }
        }
    
        if (ans[i] == 0) {
            cout << "assign ans[" << i << "] to m: " << m << '\n';
            ans[i] = m;
        }
    
        cout << "update y[" << i << "]: " << y[i] << " to SegmentTree\n";
        root->update(y[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}

/*

Trong đó, Node là một cấu trúc dữ liệu Segment Tree để lưu trữ thông tin về các hình chữ nhật theo chiều rộng (width). 
Trong hàm main(), ta sẽ nhập vào các giá trị của mảng X[] và Y[], và sắp xếp các hình chữ nhật theo chiều rộng tăng dần. 
Sau đó, ta sử dụng vòng lặp duyệt ngược từ cuối mảng X[] để tính giá trị cho mảng C[]. 
Trong vòng lặp này, ta sử dụng hàm lower_bound() để tìm vị trí của hình chữ nhật có chiều rộng lớn nhất mà có thể bao phủ vị trí hiện tại. 
Sau đó, ta duyệt các hình chữ nhật từ vị trí này đến cuối danh sách, và tìm hình chữ nhật đầu tiên có thể bao phủ vị trí hiện tại. 
Nếu không tìm thấy hình chữ nhật nào, ta sẽ gán giá trị của mảng C[] cho giá trị của M. 
Sau khi tìm được hình chữ nhật thích hợp, ta sẽ truy vấn vào Segment Tree để tính số lượng hình chữ nhật có thể bao phủ vị trí hiện tại. Cuối cùng, ta xuất kết quả của mảng C[].

Độ phức tạp thuật toán của phương pháp này là O((N+M)logM), do đó nó phù hợp với các trường hợp N và M lớn.

*/