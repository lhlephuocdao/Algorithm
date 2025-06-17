#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

// directions: 0=up, 1=right, 2=down, 3=left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug :
 *      - duplicated element
 *      - consecutive range: 1 2 3 4 5 ....
 * stress test
 */

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int nL = 0, nI = 0, nT = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') nL++;
            if (s[i] == 'I') nI++;
            if (s[i] == 'T') nT++;
        }

        if (nL == nI && nL == nT) {
            cout << 0 << '\n';
            continue;
        }

        vector<int> vm, vL, vI, vT;
        int rL = -1, rI = -1, rT = -1;
        int m, x;
        for (m = 0; m <= 2*n; m++) {
            if ((n+m)%3 != 0) continue;
            x = (n+m)/3;

            if (x<nL || x<nI || x<nT) continue;
            rL = x - nL;
            rI = x - nI;
            rT = x - nT;
            vm.push_back(m);
            vL.push_back(rL);
            vI.push_back(rI);
            vT.push_back(rT);
        }

        // cout << "rL: " << rL << " rI: " << rI << " rT: " << rT << '\n';
        // cout << "m: " << m << '\n';

        bool found = false;
        for (int q = 0; q < vm.size(); q++){
            vector<int> ans;
            bool pos = true;

            m = vm[q];
            rL = vL[q];
            rI = vI[q];
            rT = vT[q];

            string tmp = s;

            for (int i = 0; i < m; i++)
            {
                bool check = false;
                // cout << "i: " << i << '\n';
                for (int j = 0; j < tmp.length()-1; j++)
                {
                    char a = tmp[j], b = tmp[j+1];
                    // cout << "j: " << j << " a: " << a << " b: " << b << '\n';
                    if (a == b) continue;
                    char c;
                    if ((a == 'L' && b == 'I') || (a == 'I' && b == 'L')) c = 'T';
                    if ((a == 'L' && b == 'T') || (a == 'T' && b == 'L')) c = 'I';
                    if ((a == 'T' && b == 'I') || (a == 'I' && b == 'T')) c = 'L';

                    if ((c == 'L' && rL > 0) || (c == 'I' && rI > 0) || (c == 'T' && rT > 0)) {
                        ans.push_back(j+1);
                        tmp.insert(tmp.begin() + j + 1, c);
                        if (c == 'L') rL--;
                        if (c == 'I') rI--;
                        if (c == 'T') rT--;
                        check = true;
                        break;
                    }
                }

                if (check == false) {
                    pos = false;
                    break;
                }
            }

            if (pos) {
                cout << m << '\n';
                for (auto o : ans)
                    cout << o << '\n';
                found = true;
                break;
            }
        }

        if (!found)
            cout << -1 << '\n';
    }

    return 0;
}