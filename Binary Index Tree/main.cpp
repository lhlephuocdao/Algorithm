#include <bits/stdc++.h>

using namespace std;

#define MAX 20003

int A[MAX], BIT[MAX+1], N;

void update(int u, int v)
{
    int i = u + 1;
    while (i <= N)
    {
        BIT[i] += v;
        i += (i & (-i));
    }
}

int getSum(int p)
{
    int ans = 0;
    while (p > 0)
    {
        ans += BIT[p];
        p -= (p & (-p));
    }
    return ans;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        update(i, A[i]);
    }

    for (int i = 1; i <= N; i++)
        cout << BIT[i] << " ";
    cout << "\n";

    cout << getSum(9) << endl;

    return 0;
}