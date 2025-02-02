#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<long long> getDivisors(long long n) {
    vector<long long> divisors;
    
    // Iterate over all numbers from 1 to sqrt(n)
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i); // i is a divisor
            if (i != n / i) {
                divisors.push_back(n / i); // n / i is also a divisor
            }
        }
    }
    
    return divisors;
}

int countBits(int n) {
    if (n == 0) return 1;  // special case for 0
    return floor(log2(n)) + 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int x,m;
        cin >> x >> m;
        vector<int> div = getDivisors(x);
        int nums_bit = countBits(x);
        int max_value = (1<<nums_bit) - 1;
        max_value = min(max_value, m);
        vector<bool> mark(max_value+1, false);
        int count = 0;
        for (int z : div) {
            int y = x^z;
            if (y>=1 && y<=m) {
                count++;
                mark[y] = true;
            }
        }

        for (int y = 1; y <= max_value; y++) {
            if (mark[y] == false) {
                int z = x^y;
                if (z!=0 && y%z==0)
                    count++;
            }
        }
        cout << count << '\n';
    }

    return 0;
}