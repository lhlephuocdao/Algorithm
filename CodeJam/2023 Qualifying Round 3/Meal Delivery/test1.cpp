#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

const int INF = 1e9; // Đây là vô cùng, một giá trị đủ lớn để đại diện cho vô nghiệm.

int n; // Số lượng đỉnh
std::vector<std::pair<int, int>> coordinates; // Tọa độ của các đỉnh
std::vector<std::vector<int>> dp; // Ma trận lưu trữ các giá trị đã tính

// Hàm tính khoảng cách Euclidean giữa hai điểm
int distance(int i, int j) {
    int dx = abs(coordinates[i].first - coordinates[j].first);
    int dy = abs(coordinates[i].second - coordinates[j].second);
    return dx + dy;
}

// Hàm đệ quy để tính độ dài của đường đi ngắn nhất
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        // Nếu đã đi qua tất cả các đỉnh, trở về đỉnh gốc
        return distance(pos, 0);
    }

    if (dp[mask][pos] != -1) {
        // Nếu đã tính trước đó, trả về giá trị đã tính
        return dp[mask][pos];
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            // Nếu đỉnh i chưa được đi qua
            int new_mask = mask | (1 << i);
            ans = std::min(ans, distance(pos, i) + tsp(new_mask, i));
        }
    }

    // Lưu kết quả vào dp và trả về giá trị
    return dp[mask][pos] = ans;
}

int main() {
    // Nhập số lượng đỉnh
    std::cin >> n;

    // Khởi tạo ma trận dp
    dp.assign(1 << n, std::vector<int>(n, -1));

    // Nhập tọa độ của các đỉnh
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        coordinates.push_back({x, y});
    }

    // Tìm độ dài của đường đi ngắn nhất và in ra kết quả
    int ans = tsp(coordinates[0].first, coordinates[0].second); // Bắt đầu từ đỉnh gốc ở vị trí 0
    std::cout << "Tong quang duong ngan nhat: " << ans << std::endl;

    return 0;
}
