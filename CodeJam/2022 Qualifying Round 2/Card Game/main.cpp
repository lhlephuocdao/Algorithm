#include <bits/stdc++.h>

using namespace std;

int reverse(int s)
{
    int ans = 0;

    while (s)
    {
        int t = s%10;
        ans = ans*10 + t;
        s /= 10;
    }
    return ans;
}

void divide(vector<int>& arr, int S)
{
    while (S)
    {
        int t = S%10;
        arr.push_back(t);
        S /= 10;
    }

    reverse(arr.begin(), arr.end());
}

int T, n, B, A, sol;
bool mark[8], first = true;
vector<int> Bob, Alice;
int ans[8];

int convert(int* p)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret = 10*ret + p[i];
    }

    return ret;
}

void brute(int index)
{
    for (int i = 0; i < n && first; i++)
    {

        if (mark[i] == false) {
            ans[index] = Alice[i];
        } else continue;
        

        if (index == n-1)
        {
            int tmp = convert(ans);
            if (tmp < B && first)
            {
                sol = tmp;
                first = false;
                return;
            }
        } else {
            mark[i] = true;
            brute(index + 1);
            mark[i] = false;
        }
    }
}

void solve()
{

    for (int i = 0; i < n; i++)
    {
        mark[i] = false;
        ans[i] = 0;
    }

    brute(0);

}

int main()
{

    cin >> T;
    while (T--)
    {
        sol = 0;
        first = true;
        cin >> n >> B >> A;

        int tmp = reverse(B);
        B = (tmp > B) ? B : tmp;

        Bob.clear();
        divide(Bob, B);

        Alice.clear();
        divide(Alice, A);

        sort(Alice.begin(), Alice.end(), greater<int>());

        solve();
        
        if (sol == 0) {
            Alice.pop_back();
            for (int i = 0; i < Alice.size(); i++)
            {
                sol = 10*sol + Alice[i];
            }
        }

        cout << sol << endl;
    }

    return 0;
}