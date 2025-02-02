#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 4e5 + 5;
int Nx, Ny, Nz, t;
string Sx, Sy, Sz;

ll solve2(int colorX, int colorY, int colorZ, int x, int y, int z, int ansx, int ansy, int ansz)
{
    char firstRow, secondRow, thirdRow;
    if (colorX == 1) firstRow = 'R';
    if (colorX == 2) firstRow = 'G';
    if (colorX == 3) firstRow = 'B';
    if (colorY == 1) secondRow = 'R';
    if (colorY == 2) secondRow = 'G';
    if (colorY == 3) secondRow = 'B';
    if (colorZ == 1) thirdRow = 'R';
    if (colorZ == 2) thirdRow = 'G';
    if (colorZ == 3) thirdRow = 'B';
    ll res = 0;
    ll firstRowPairs = 0, secondRowPairs = 0, thirdRowPairs = 0;
    ll countFirstRow = 0, countSecondRow = 0, countThirdRow = 0;

    if (colorX == x) {
        firstRowPairs = ansx;
    } else {
        for (int i = 0; i < Sx.size(); i++) {
            if (Sx[i] == firstRow) {
                countFirstRow++;
            } else {
                firstRowPairs += max(0ll, countFirstRow - 1);
                countFirstRow = 0;
            }
        }
        firstRowPairs += max(0ll, countFirstRow - 1);
        firstRowPairs = min(firstRowPairs, (long long)Sx.size() - 1);
    }

    if (colorY == y) {
        secondRowPairs = ansy;
    } else {
        for (int i = 0; i < Sy.size(); i++) {
            if (Sy[i] == secondRow) {
                countSecondRow++;
            } else {
                secondRowPairs += max(0ll, countSecondRow - 1);
                countSecondRow = 0;
            }
        }
        secondRowPairs += max(0ll, countSecondRow - 1);
        secondRowPairs = min(secondRowPairs, (long long)Sy.size() - 1);
    }

    if (colorZ == z) {
        thirdRowPairs = ansz;
    } else {
        for (int i = 0; i < Sz.size(); i++) {
            if (Sz[i] == thirdRow) {
                countThirdRow++;
            } else {
                thirdRowPairs += max(0ll, countThirdRow - 1);
                countThirdRow = 0;
            }
        }
        thirdRowPairs += max(0ll, countThirdRow - 1);
        thirdRowPairs = min(thirdRowPairs, (long long)Sz.size() - 1);
    }

    res = 1ll*firstRowPairs * secondRowPairs * thirdRowPairs;
    cout << "solve2: " << firstRow << " " << secondRow << " " << thirdRow << '\n';
    cout << "solve2: " <<  firstRowPairs << " " << secondRowPairs << " " << thirdRowPairs << '\n';
    return res;
}

ll solve(int colorX, int colorY, int colorZ) {
    char firstRow, secondRow, thirdRow;
    if (colorX == 1) firstRow = 'R';
    if (colorX == 2) firstRow = 'G';
    if (colorX == 3) firstRow = 'B';
    if (colorY == 1) secondRow = 'R';
    if (colorY == 2) secondRow = 'G';
    if (colorY == 3) secondRow = 'B';
    if (colorZ == 1) thirdRow = 'R';
    if (colorZ == 2) thirdRow = 'G';
    if (colorZ == 3) thirdRow = 'B';
    ll res = 0;
    ll firstRowPairs = 1, secondRowPairs = 1, thirdRowPairs = 1;
    ll countFirstRow = 0, countSecondRow = 0, countThirdRow = 0;
    bool flagChangeFirstRow = false, flagChangeSecondRow = false, flagChangeThirdRow = false;

	size_t found1 = Sx.find(firstRow);
    if (found1 == string::npos) firstRowPairs = 0;
    for (int i = 0; i < Sx.size(); i++) {
        if (Sx[i] == firstRow && i + 1 < Sx.size() && Sx[i + 1] != firstRow && i + 2 < Sx.size() && Sx[i + 2] == firstRow && flagChangeFirstRow == false) {
            firstRowPairs++;
            flagChangeFirstRow = true;
        }
        if (Sx[i] == firstRow) {
            countFirstRow++;
        } else {
            firstRowPairs += max(0ll, countFirstRow - 1);
            countFirstRow = 0;
        }
    }
    
    firstRowPairs += max(0ll, countFirstRow - 1);
    firstRowPairs = min(firstRowPairs, (long long)Sx.size() - 1);

	size_t found2 = Sy.find(secondRow);
    if (found2 == string::npos) secondRowPairs = 0;
    for (int i = 0; i < Sy.size(); i++) {
        if (Sy[i] == secondRow && i + 1 < Sy.size() && Sy[i + 1] != secondRow && i + 2 < Sy.size() && Sy[i + 2] == secondRow && flagChangeSecondRow == false) {
            secondRowPairs++;
            flagChangeSecondRow = true;
        }
        if (Sy[i] == secondRow) {
            countSecondRow++;
        } else {
            secondRowPairs += max(0ll, countSecondRow - 1);
            countSecondRow = 0;
        }
    }

    secondRowPairs += max(0ll, countSecondRow - 1);
    secondRowPairs = min(secondRowPairs, (long long)Sy.size() - 1);

	size_t found3 = Sz.find(thirdRow);
    if (found3 == string::npos) thirdRowPairs = 0;
    for (int i = 0; i < Sz.size(); i++) {
        if (Sz[i] == thirdRow && i + 1 < Sz.size() && Sz[i + 1] != thirdRow && i + 2 < Sz.size() && Sz[i + 2] == thirdRow && flagChangeThirdRow == false) {
            thirdRowPairs++;
            flagChangeThirdRow = true;
        }
        if (Sz[i] == thirdRow) {
            countThirdRow++;
        } else {
            thirdRowPairs += max(0ll, countThirdRow - 1);
            countThirdRow = 0;
        }
    }

    thirdRowPairs += max(0ll, countThirdRow - 1);
    thirdRowPairs = min(thirdRowPairs, (long long)Sz.size() - 1);
    
    cout << firstRow << " " << secondRow << " " << thirdRow << '\n';
    cout << firstRowPairs << " " << secondRowPairs << " " << thirdRowPairs << '\n';
     
    res = 1ll*firstRowPairs * secondRowPairs * thirdRowPairs;

    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++) {
                if (i == j || j == k || i == k) continue;
                if (i == colorX && j == colorY && k == colorZ) continue;
                ll tmp = solve2(i, j, k, colorX, colorY, colorZ, firstRowPairs, secondRowPairs, thirdRowPairs);
                res += tmp;
                cout << "solve: " << res << '\n';
            }

    return res;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> Nx >> Ny >> Nz;
        cin >> Sx >> Sy >> Sz;
        ll ans = 0;
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                for (int k = 1; k <= 3; k++) {
                    if (i == j || j == k || i == k) continue;
                    ans = max(ans, solve(i, j, k));
                }
            }
        }
        cout << ans << '\n';
    }
}