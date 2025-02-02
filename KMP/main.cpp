#include <bits/stdc++.h>

using namespace std;

#define MAX 1000003

string A, B;

void construct_lps(int lps[], int M)
{
    int len = 0, i = 1;
    while (i < M)
    {
        if (B[len] == B[i])
        {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) 
                len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void solve(int N, int M)
{
    int lps[M];
    lps[0] = 0;

    construct_lps(lps, M);

    int i = 0, j = 0;
    while (N-i >= M-j)
    {
        if (A[i] == B[j])
        {
            i++;
            j++;
        } else {
            if (j != 0)
                j = lps[j-1];
            else
                i++;
        }

        if (j == M)
        {
            cout << i - j + 1 << " ";
            j = lps[j-1];
        }
    }

    // for (int i = 0; i < M; i++)
    //     cout << lps[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> A >> B;
    int N = A.length();
    int M = B.length();

    solve(N, M);

    return 0;
}