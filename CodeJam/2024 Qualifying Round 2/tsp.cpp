#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int tsp(int pos, int mask, const std::vector<std::vector<int>>& dist, std::vector<std::vector<int>>& dp) {
    int n = dist.size();

    // If all cities are visited, return to the starting city
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Return to the start city
    }

    // If already computed, return the stored result
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int minCost = INF;

    // Try to go to any city that hasn't been visited yet
    for (int city = 0; city < n; ++city) {
        if ((mask & (1 << city)) == 0) {
            int newCost = dist[pos][city] + tsp(city, mask | (1 << city), dist, dp);
            minCost = std::min(minCost, newCost);
        }
    }

    return dp[pos][mask] = minCost;
}

int main() {
    int n;
    std::cout << "Enter the number of cities: ";
    std::cin >> n;

    std::vector<std::vector<int>> dist(n, std::vector<int>(n));

    std::cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> dist[i][j];
        }
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(1 << n, -1));

    int minCost = tsp(0, 1, dist, dp);

    std::cout << "Minimum travel cost: " << minCost << std::endl;

    return 0;
}
