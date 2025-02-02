#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e5 + 7;
int n;

struct point {
    int A;
    int B;
    int sum;
};

bool compare(const point& a, const point& b)
{
    if (a.sum > b.sum) return true;
    else return false;
}

void solve()
{
    cin >> n;
    vector<point> P(n);
    for (int i = 0; i < n; i++)
    {
        cin >> P[i].A >> P[i].B;
        P[i].sum = P[i].A + P[i].B;
    }

    sort(P.begin(), P.end(), compare);

    ll sumA = 0, sumB = 0;
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0) sumA += P[i].A;
        else sumB += P[i].B;
    }

    cout << sumA - sumB << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}