#include <bits/stdc++.h>

using namespace std;

const int maxN = 9;
int n;
int D[maxN][maxN][maxN];

/*
    methodFlag: nhung methods con lai ma chua duoc dung
    cityFlag: nhung thanh pho con lai ma chua duoc tham
*/
int tsp(int methodFlag, int from_city, int cityFlag, vector<vector<vector<int>>>& _memory,bool find_min)
{
    int& memo = _memory[methodFlag][from_city][cityFlag];
    if (memo != -1) {
        return memo;
    }

    if (__builtin_popcount(methodFlag) == 1 && __builtin_popcount(cityFlag) == 0) {
        int method = __builtin_ctz(methodFlag);
        if (D[method][from_city][0] == 0) {
            if (find_min) return INT_MAX;
            else return INT_MIN;
        }

        return D[method][from_city][0];
    }

    memo = find_min ? INT_MAX : INT_MIN;
    for (int k = 0; k < n; k++)
    {
        if (!(methodFlag & (1 << k))) continue; //method k da duoc su dung

        for (int i = 0; i < n; i++)
        {
            if (!(cityFlag & (1<<i))) continue; //city i da duoc tham
            if (D[k][from_city][i] == 0) continue; //khong co duong di tu from_city den city i bang method k

            int v = D[k][from_city][i];
            int u = tsp((methodFlag & ~(1<<k)), i, (cityFlag & ~(1<<i)), _memory, find_min);
            if (find_min) {
                if (u != INT_MAX) {
                    v += u;
                    memo = std::min(memo, v);
                }
            } else {
                if (u != INT_MIN) {
                    v += u;
                    memo = std::max(memo, v);
                }
            }
        }
    }

    return memo;
}

void solve()
{
    memset(D, 0, sizeof(D));
    cin >> n;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> D[k][i][j];

    int max_ans = INT_MIN;
    int min_ans = INT_MAX;
    int cityFlag = (1<<n)-1;
    int methodFlag = (1<<n)-1;

    vector<vector<vector<int>>> dpMin(1<<maxN, vector<vector<int>>(maxN, vector<int>(1<<maxN, -1)));
    vector<vector<vector<int>>> dpMax(1<<maxN, vector<vector<int>>(maxN, vector<int>(1<<maxN, -1)));

    for (int k = 0; k < n; k++) {
        int v = tsp(methodFlag, 0, cityFlag & ~(1<<0), dpMin, true);
        min_ans = std::min(min_ans, v);
    }

    for (int k = 0; k < n; k++) {
        int v = tsp(methodFlag, 0, cityFlag & ~(1<<0), dpMax, false);
        max_ans = std::max(max_ans, v);
    }

    if (min_ans != INT_MAX && max_ans != INT_MIN)
        cout << min_ans << " " << max_ans << '\n';
    else
        cout << 0 << " " << 0 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}