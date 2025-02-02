#include <bits/stdc++.h>

using namespace std;

const double EPSILON = 1e-3;
const int maxn = 1e5 + 7;
int n, x;
double P[maxn];
double sum = 0;

bool compare(double a, double b)
{
    return fabs(a - b) < EPSILON;
}

bool check_min(int val)
{
    double f = sum*(double)val/100;
    f = f*100;
    double hi = ceil(f);
    double t = 100*((double)x - sum);
    if (hi > t || compare(hi, t)) return true;
    else return false;
}

bool check_max(int val)
{
    double f = sum*(double)val/100;
    f *= 100;
    double lo = floor(f);
    double t = 100*((double)x + 1.0 - sum);
    if (lo > t || compare(lo, t)) return false;
    else return true;
}

void solve()
{
    cin >> n >> x;
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> P[i];
        sum += P[i];
    }

    double upper = 100*((double)x + 1.0 - sum)/sum;
    double lower =  100*((double)x - sum)/sum;

    int min1 = (int)lower;
    int min2 = min1 + 1;
    int min3 = min1 - 1;

    if (!check_min(min1))  {  min1 = INT_MAX;}
    if (!check_min(min2)) {  min2 = INT_MAX;}
    if (!check_min(min3)) {  min3 = INT_MAX;}

    int min_val = std::min(min1, std::min(min2, min3));
    if (min_val < 0) min_val = 0;

    int max1 = (int)upper;
    int max2 = max1 + 1;
    int max3 = max1 - 1;

    if (!check_max(max1)) {  max1 = INT_MIN;}
    if (!check_max(max2)) {  max2 = INT_MIN;}
    if (!check_max(max3)) {  max3 = INT_MIN;}

    int max_val = std::max(max1, std::max(max2, max3));
    cout << min_val << " " << max_val << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}