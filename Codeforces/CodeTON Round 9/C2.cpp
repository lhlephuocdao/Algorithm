#include <bits/stdc++.h>
using namespace std;
#define int long long

int countBits(int n) {
    if (n == 0) return 1;  // special case for 0
    return floor(log2(n)) + 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
        // auto start = std::chrono::high_resolution_clock::now();
    while (t--)
    {
        int x,m;
        cin >> x >> m;
        int count = 0;
        for (int y = 1; y <= min(x,m); y++) {
            int z = x^y;
            if (z%y == 0) {
                count++;
            }
        }

        if (x < m) {
            int t = m/x - 1;
            count += t-1; // get i = [2, t], i = 1 (-> k = x) is already calculated above

            for(long long i=t+1;i<=t+x*2;i++){
                long long k=x^(x*i);
                if(k<=m) count++;
            }
        }
        cout << count << '\n';
    } 
        // auto end = std::chrono::high_resolution_clock::now(); // End time
        // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        // std::cout << "Execution time: " << duration.count() << " milliseconds\n";

    return 0;
}