#include <bits/stdc++.h>

using namespace std;

int T, A, B, X;

int GCD(int a, int b)
{
    while (a*b != 0)
    {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }

    return a+b;
}

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> A >> B >> X;
        int tmp = GCD(A, B);
        cout << X/tmp << endl;
    }

    return 0;
}