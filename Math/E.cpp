#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> x;
int maxx = INT_MIN;

int solve()
{
    int di[maxx+1];
    memset(di, 0, sizeof(di));
    for (int i = 0; i < n; i++)
        di[x[i]]++;

    for (int i = maxx; i >= 1; i--)
    {
        int count = 0, j = i;
        while (j <= maxx)
        {
            if (di[j] >= 2)
                return j;
            else if (di[j] == 1) count++;

            if (count == 2) return i;

            j += i;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    x.clear();
    x.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        maxx = std::max(maxx, x[i]);
    }

    cout << solve() << '\n';

    return 0;
}