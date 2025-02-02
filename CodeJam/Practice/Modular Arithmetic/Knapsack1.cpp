#include <bits/stdc++.h>

using namespace std;
const int maxw = 1e5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, WW;
    cin >> N >> WW;
    int w[N], v[N];
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

    /*
        F[i][j] : maximum values to choose some of from the first i items and weights <= j
        F[i][j] -> Caculate F[i+1][j + w[i+1]] = F[i][j] + v[i+1] (Case 1: choose item i+1)
                -> F[i+1][j] = F[i][j] (Case 2: don't choose item i+1)
    */

   long long F[110][maxw + 7];
   memset(F, 0, sizeof(F));
   for (int j = 1; j <= WW; j++)
        if (j < w[0]) F[0][j] = 0;
        else F[0][j] = v[0];

   for (int i = 0; i < N-1; i++)
   {
        for (int j = 1; j <= WW; j++)
        {
            F[i+1][j + w[i+1]] = std::max(F[i+1][j + w[i+1]], F[i][j] + v[i+1]);
            F[i+1][j] = std::max(F[i+1][j], F[i][j]);
        }
   }

    cout << F[N-1][WW] << '\n';

    return 0;
}