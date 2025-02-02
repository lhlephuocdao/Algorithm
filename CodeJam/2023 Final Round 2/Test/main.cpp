#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n,m,k;

void calc(vector<int>& v, vector<int>& ret)
{
    int nn = v.size();
    int lim = 1 << nn;

    for (int tt = 0; tt < lim; tt++)
    {
        int sum = 0, cnt = 0;
        for (int i = 0; i < nn; i++)
        {
            if (tt & (1<<i))
            {
                sum += v[i];
                cnt++;
            }
        }

        if (cnt == k) ret.push_back(sum);
    }
}

void solve()
{
    cin >> n >> m >> k;
    vector<int> A, B;
    B.resize(n); A.resize(m);

    for (int i = 0; i < n; i++) cin >> B[i];
    for (int j = 0; j < m; j++) cin >> A[j];

    vector<int> comA, comB;
    calc(B, comB);
    calc(A, comA);
    sort(comA.begin(), comA.end());
    sort(comB.begin(), comB.end());

    int min_diff = INT_MAX, max_diff = INT_MIN;
    for (auto a : comA) {
        auto itr = lower_bound(comB.begin(), comB.end(), a);
        if (itr != comB.end()) {
            min_diff = std::min(min_diff, abs(*itr - a));
        }
    }

    for (auto b : comB) {
        auto itr = lower_bound(comA.begin(), comA.end(), b);
        if (itr != comA.end()) {
            min_diff = std::min(min_diff, abs(*itr - b));
        }
    }

    int t1 = abs(comA[0] - comB.back());
    int t2 = abs(comB[0] - comA.back());
    max_diff = std::max(t1, t2);
    cout << min_diff << " " << max_diff << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}