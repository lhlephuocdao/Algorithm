#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
#include <cmath>

using namespace std;

void solve();

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::vector<long long> d(n - 1);

    std::string input;
    std::getline(std::cin, input);
    std::istringstream tokenizer(input);

    for (int j = 0; j < n - 1; j++) {
        tokenizer >> d[j];
    }

    long long s = 0;
    long long e = static_cast<long long>(std::pow(10, 20));

    while (s != e) {
        // mid : maximum energy needed
        long long mid = (s + e) / 2;
        long long a = 0;
        long long cur = 0;
        int cnt = 0;
        int group = 1;

        for (int i = 0; i < n-1; i++) {
            long long num = d[i];
            cnt++;
            a += num * cnt;
            cur += a;

            if (cur > mid) {
                // if at i, energy of a consecutive rooms is greater than mid
                // => energy of a consecutive rooms exclude is less than or equal to mid
                // => the d[i] is removed, d[i] is the distance between room i and i+1
                // => room i belongs to the current group
                // => room i+1 belongs to the next group
                a = 0;
                cur = 0;
                cnt = 0;
                group++;
            }
        }

        if (group > m) {
            s = mid + 1;
        } else {
            e = mid;
        }
    }

    std::cout << e << std::endl;
}