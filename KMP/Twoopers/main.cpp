#include <bits/stdc++.h>

using namespace std;

string S,T;
int N, M;

void computeLPSArray(string pat, int* lps)
{
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }

        }
    }
}

long long KMPSearch(string pat, string txt, int* lps)
{
    int i = 0, j = 0, mark = 0;
    bool shift = true;
    long long ans = 0;

    while (i < N-1 && j < M) {
        if (pat[j] == txt[i] || shift)
        {
            if (pat[j] != txt[i]) {
                shift = false;
                mark = i;
            }
            i++;
            j++;
        } else if (i < N && pat[j] != txt[i] && !shift)
        {
            if (j != 0)
            {
                int tmp = j;
                j = lps[j-1];
                if (tmp-j > i-mark) {
                    i -= (tmp-j)-(i-mark);
                    mark = 0;
                    shift = true;
                }
            }
            else 
                i = i + 1;

            if (i-j > mark)
            {
                mark = 0;
                shift = true;
            }
        }

        if (j == M) {
            if (shift) ans += M;
            else ans++;

            j = lps[j-1];

            if (i-j > mark)
            {
                mark = 0;
                shift = true;
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> S >> T;

    S = S + S;
    M = T.size();
    N = M * 2;

    int lpsT[M], lpsS[M];

    computeLPSArray(S, lpsS);
    computeLPSArray(T, lpsT);

    if (lpsT[M-1] >= lpsS[M-1]) {
        S = S + S;
        cout << KMPSearch(T, S, lpsT) << endl;
    } else {
        T = T + T;
        cout << KMPSearch(S, T, lpsS) << endl;
    }

    return 0;
}