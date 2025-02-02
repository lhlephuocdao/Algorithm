#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n,T,L,F;

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> n >> L >> F;
        string s;
        int ans = 0;

        vector<string> W;

        //input
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            W.push_back(s);
        }

        map<string, int> check;
        for (int i = 0; i < n; i++)
        {
            string t = W[i];
            string tmp;
            for (int k = L-F; k<L; k++)
                tmp += t[k];

            check[tmp]++;
        }

        for (auto str : check)
        {
            ans += str.second / 2;
        }

        cout << ans << endl;

    }
    
    return 0;
}