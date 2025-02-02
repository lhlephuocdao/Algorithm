#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int tsp(const std::vector<std::vector<std::vector<int>>> &D, int city, int mask, int methodMask, std::vector<std::vector<std::vector<int>>> &dp, bool findMin) {
    int N = D.size();

    // If all cities are visited and all methods are used
    if (mask == (1 << N) - 1 && methodMask == (1 << N) - 1) {
        return D[__builtin_ctz(~methodMask)][city][0]; // Return to the start city using the remaining method
    }

    if (dp[city][mask][methodMask] != -1) {
        return dp[city][mask][methodMask];
    }

    int optimalTime = findMin ? INF : -INF;

    for (int nextCity = 0; nextCity < N; ++nextCity) {
        if (mask & (1 << nextCity)) continue; // Skip if the city is already visited

        for (int method = 0; method < N; ++method) {
            if (methodMask & (1 << method)) continue; // Skip if the method is already used

            if (D[method][city][nextCity] == 0) continue; // No valid route

            int nextMask = mask | (1 << nextCity);
            int nextMethodMask = methodMask | (1 << method);
            int travelTime = D[method][city][nextCity] + tsp(D, nextCity, nextMask, nextMethodMask, dp, findMin);

            if (findMin) {
                optimalTime = std::min(optimalTime, travelTime);
            } else {
                optimalTime = std::max(optimalTime, travelTime);
            }
        }
    }

    dp[city][mask][methodMask] = optimalTime;
    return optimalTime;
}

int main() {
    int N;
    std::cout << "Enter the number of cities (N): ";
    std::cin >> N;

    std::vector<std::vector<std::vector<int>>> D(N, std::vector<std::vector<int>>(N, std::vector<int>(N, 0)));

    std::cout << "Enter the travel times for each method (k), city (i), and city (j):\n";
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cin >> D[k][i][j];
            }
        }
    }

    std::vector<std::vector<std::vector<int>>> dpMin(N, std::vector<std::vector<int>>(1 << N, std::vector<int>(1 << N, -1)));
    std::vector<std::vector<std::vector<int>>> dpMax(N, std::vector<std::vector<int>>(1 << N, std::vector<int>(1 << N, -1)));

    int minTime = tsp(D, 0, 1, 0, dpMin, true);
    int maxTime = tsp(D, 0, 1, 0, dpMax, false);

    std::cout << "Minimum travel time: " << minTime << std::endl;
    std::cout << "Maximum travel time: " << maxTime << std::endl;

    return 0;
}
