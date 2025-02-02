#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

int T, n;
vector<int> length;

long long solve(int* A)
{   
    int s = 0, e = 0;
    long long ans = 0;
    bool larger = true, smaller = true;
    for (int i = 0; i < n-1; i++)
    { 
        if ((larger && A[i] < A[i+1]) || (smaller && A[i] > A[i+1]))
        {
            if (A[i] < A[i+1]) {
                larger = false;
                smaller = true;
            }

            if (A[i] > A[i+1]) {
                smaller = false;
                larger = true;
            }

            e = i+1;
        } else {
            larger = true;
            smaller = true;
            length.push_back(e-s+1);
            if (A[i] == A[i+1]) {
                s = i + 1;
                e = i + 1;
            } else {
                i--;
                s = e;
            }
        }

        if (i+1 == n-1)
            if (s != e) length.push_back(e-s+1);
            else if (A[i] != A[i+1]) length.push_back(2);
    }

    for (int i = 0; i < length.size(); i++)
    {
        int t = length[i];
        if (t > 1)
        {
            ans += 1LL * t * (t-1) / 2;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    while (T--)
    {
        cin >> n;
        length.clear();
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];

        long long ans = solve(A);
        cout << ans << endl;
    }

    return 0;
}