#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG_INF = (ll)-4e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        cin >> a[i][j];

    // prev[j][k]: best at (i-1, j) with k downs-in-a-row
    // cur [j][k]: best at (i,   j) with k downs-in-a-row
    vector<array<ll,3>> prev(m, {NEG_INF, NEG_INF, NEG_INF});
    vector<array<ll,3>> cur (m, {NEG_INF, NEG_INF, NEG_INF});

    // base case at (0,0)
    prev[0][0] = a[0][0];

    // fill row 0 by moving only right
    for(int j = 1; j < m; j++){
      prev[j][0] = prev[j-1][0] + a[0][j];
    }

    // DP rows 1..n-1
    for(int i = 1; i < n; i++){
      // column 0: can only come from above
      cur[0][0] = NEG_INF;
      cur[0][1] = prev[0][0] + a[i][0];
      cur[0][2] = prev[0][1] + a[i][0];

      for(int j = 1; j < m; j++){
        // move right → resets down‑count to 0
        ll bestFromLeft = max({ cur[j-1][0],
                                cur[j-1][1],
                                cur[j-1][2] });
        cur[j][0] = bestFromLeft + a[i][j];

        // move down → increments down‑count
        cur[j][1] = prev[j][0] + a[i][j];
        cur[j][2] = prev[j][1] + a[i][j];
      }

      swap(prev, cur);
      // clear cur for next iteration
      fill(cur.begin(), cur.end(), array<ll,3>{NEG_INF,NEG_INF,NEG_INF});
    }

    ll ans = max({ prev[m-1][0],
                   prev[m-1][1],
                   prev[m-1][2] });
    cout << ans << "\n";
    return 0;
}
