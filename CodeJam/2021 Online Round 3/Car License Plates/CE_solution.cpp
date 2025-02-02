#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;
 
struct Plate {
        static const short N_ALPHA = 26;
        short capital;
        short alpha[N_ALPHA];
 
        bool operator <(const Plate &rhs) const {
                if (capital != rhs.capital)
                        return capital < rhs.capital;
                for (int i = 0; i < N_ALPHA; ++i)
                        if (alpha[i] != rhs.alpha[i])
                                return alpha[i] < rhs.alpha[i];
                return false;
        }
 
        friend istream &operator >>(istream &is, Plate &plate) {
                string s;
                is >> s;
                plate.capital = 0;
                fill(begin(plate.alpha), end(plate.alpha), 0);
                for (char c : s) {
                        if (!isalpha(c))
                                continue;
                        if (isupper(c)) {
                                ++plate.capital;
                                c = tolower(c);
                        }
                        ++plate.alpha[c-'a'];
                }
                return is;
        }
};
 
long long nC2(long long n) {
        if (n < 2)
                return 0;
        return (n * (n - 1)) / 2;
}
 
int solve(map<Plate,int> &m) {
        long long ans = 0;
        for (const auto &[_, cnt] : m)
                ans += nC2(cnt);
        return ans;
}
 
int main(void) {
        cout.sync_with_stdio(false);
        cin.tie(nullptr);
        int nTests;
        cin >> nTests;
        while (nTests--) {
                int n, k;
                cin >> n >> k;
 
                map<Plate,int> m;
                for (int i = 0; i < n; ++i) {
                        Plate p;
                        cin >> p;
                        ++m[p];
                }
 
                cout << solve(m) << '\n';
        }
        return 0;
}