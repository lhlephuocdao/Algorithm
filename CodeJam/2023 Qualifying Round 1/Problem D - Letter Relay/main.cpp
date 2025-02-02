#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

const int MAXN = 250005;
int F[MAXN], vis[MAXN];

//ƯCLN
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

//BCNN
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int cycle_size(int start) {
    int curr = start, size = 0;
    do {
        vis[curr] = true;
        curr = F[curr];
        size++;
    } while (curr != start);
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> F[i];
            vis[i] = false;
        }

        int num_cycles = 0;
        long long cycle_lcm = 1;
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                num_cycles++;
                int size = cycle_size(i);
                cycle_lcm = lcm(cycle_lcm, size);
            }
        }


        long long score = cycle_lcm;
        long long min_score = score;
        

        cout << score << " " << min_score << "\n";
    }

    return 0;
}