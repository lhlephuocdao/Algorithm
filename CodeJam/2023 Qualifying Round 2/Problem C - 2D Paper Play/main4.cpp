#include <bits/stdc++.h>

using namespace std;

// Định nghĩa một hình chữ nhật
struct Rectangle {
    int w, h;
};

// So sánh hai hình chữ nhật theo chiều rộng
bool compareRectangles(const Rectangle& a, const Rectangle& b) {
    return a.w < b.w;
}

// Tìm số lượng hình chữ nhật có thể bao phủ mỗi vị trí trên grid
void countCoveringRectangles(int N, int X[], int Y[], int M, Rectangle rectangles[], int C[]) {
    // Sắp xếp các hình chữ nhật theo chiều rộng và chiều cao
    sort(rectangles, rectangles + M, compareRectangles);

    // Duyệt qua từng vị trí i trên grid
    for (int i = 0; i < N; i++) {
        // Tìm kiếm nhị phân trên mảng W[] để tìm các hình chữ nhật có thể bao phủ i
        int left = 0, right = M - 1, lastValid = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (rectangles[mid].w <= X[i]) {
                lastValid = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Nếu không tìm thấy hình chữ nhật nào có thể bao phủ i, bỏ qua vị trí i này
        if (lastValid == -1) {
            C[i] = 0;
            continue;
        }

        // Tìm kiếm nhị phân trên mảng H[] để tìm các hình chữ nhật có thể bao phủ i
        int count = 0;
        left = lastValid, right = M - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (rectangles[mid].h <= Y[i]) {
                count = mid - lastValid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Lưu số lượng hình chữ nhật có thể bao phủ i vào mảng C[]
        C[i] = count;
    }
}