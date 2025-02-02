#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long

double epsilon = 1e-3;

int N, X;
double S;

bool check(int rate) {
    double h = ceil(S * rate) / 100;

    if (abs(S+h-X) < epsilon) 
    {
        return true;
    } else if (S+h - X > 0) return true;
    else return false;
}

bool check2(int rate) {
    double n = S * rate;
    int m = round(n);
    double l;
    if (abs(n-m) < epsilon)
         l = floor(m) / 100;
    else
         l = floor(n) / 100;

    if (abs(S+l - X - 1) < epsilon) return false;
    else if (S+l < X + 1) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int T;
    cin >> T;

    while (T--) {
        int min_rate, max_rate;
        cin >> N >> X;
        float P[N];
        S = 0.0;

        FOR(i,0,N) {
            cin >> P[i];
            S += P[i];
        }

        double diff = X - S;
        if (diff <= 0) min_rate = 0;
        else {
            int min1 = (diff/S) * 100;
            if (check(min1)) min_rate = min1;
            else min_rate = min1+1;
        }

        double diff2 = (X + 1 - S) / S * 100;
        int max1 = floor(diff2);

        if (check2(max1)) max_rate = max1;
        else max_rate = max1 - 1;

        cout << min_rate << " " << max_rate << '\n';
    }

    return 0;
}