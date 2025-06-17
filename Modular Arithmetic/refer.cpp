#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
 
#define M           (24*60*60)
int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
}
 
int phi(long long n) {
        long long r = n;
        for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                        while (n % i == 0)
                                n /= i;
                        r -= r / i;
                }
        }
        if (n > 1)
                r -= r / n;
        return r;
}
 
int mpow(int x, int y, int m) {
        if (y == 0) return 1;
        if (y == 1) return x;
        long long ans = mpow(x, y / 2, m);
        ans = (ans * ans) % m;
        if (y & 1)
                ans = (ans * x) % m;
        return ans;
}
 
int minv(int a, int m) {
        return mpow(a, phi(m) - 1, m);
}
 
int solve(vector<pair<int,int> > &line) {
        vector<int> X(M + 1, -1), cnt(M + 1);
        int n = line.size();
        /* first step */
        for (int i = 1; i < n; ++i) {
                int A = ((((line[i].first%M) - (line[0].first%M)) % M) + M) % M;
                int B = (line[0].second - line[i].second + M) % M;
                int G = gcd(A, M);
                if (B % G != 0)
                        return 0;
 
                int a = A / G, b = B / G, m = M / G;
                int x = ((long long)b * minv(a, m)) % m;
                cout << "A: " << A << " B: " << B << " G: " << G << "\n";
                cout << "a: " << a << " b: " << b << " m: " << m << "\n";
                cout << "x: " << x << '\n';
                if (X[m] >= 0 && X[m] != x)
                        return 0;
 
                X[m] = x;
                ++cnt[m];
        }
 
        /* second step */
        int ans = 0;
        vector<int> total(M + 1);
        for (int m = 1; m <= M; ++m) {
                if (X[m] < 0)
                        continue;
                cout << "X[" << m << "]: " << X[m] << '\n'; 
                for (int x = X[m]; x < M; x += m) {
                        total[x] += cnt[m];
                        cout << "cnt[" << m << "]: " << cnt[m] << '\n';
                        cout << "total[" << x << "]: " << total[x] << '\n';
                        if (total[x] + 1 == n)
                                ++ans;
                }
        }
        return ans;
}
 
int to_second(const string &s) {
        int hour = (s[0] - '0') * 10 + (s[1] - '0');
        int min = (s[3] - '0') * 10 + (s[4] - '0');
        int sec = (s[6] - '0') * 10 + (s[7] - '0');
        return hour * 60 * 60 + min * 60 + sec;
}
 
int main(void) {
        cout.sync_with_stdio(false);
        cin.tie(nullptr);
        int nTests;
        cin >> nTests;
        while (nTests--) {
                int n;
                cin >> n;
                vector<pair<int,int> > line(n);
                for (int i = 0; i < n; ++i) {
                        string s;
                        cin >> s;
                        line[i].second = to_second(s);
                }
                for (int i = 0; i < n; ++i)
                        cin >> line[i].first;
                cout << solve(line) << '\n';
        }
        return 0;
}