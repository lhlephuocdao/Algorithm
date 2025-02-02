#include <bits/stdc++.h>

using namespace std;

#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
#define ull unsigned long long
#define M 1000000007

int R, C, K;
string S;
bool mark[10];
bool check[500][10];
int nums_rows[10];
ull ans = 0;

ull c(int k, int n)
{
    ull a[k+1][n+1];
    if (k==0||k==n) return 1;
    else for (int i=0;i<=k;i++)
        for (int j=i;j<=n;j++)
            if (i==0||i==j) a[i][j]=1;
            else a[i][j]=a[i][j-1]+a[i-1][j-1];
            
    return a[k][n];
}

void find_rows() {
    FOR (j,0,C-1) {
        FOR(i,0,R) {
            if (check[i][j] == false && check[i][j+1] == false) {
                nums_rows[j]++;
            }
        }
    }
}

bool cal(int Rows, int index, ull mul)
{
    ull mult = mul;
    bool even;
    if (S[index] == '+') even = true;
    else even = false;

    int range;
    if (even) {
        range = Rows/2;
    } else {
        range = (Rows-1)/2;
        S[index] = '+';
        if (S[index+1] == '+') S[index+1] = '-';
        else S[index+1] = '+';
    }

    for (int i = 0; i <= range; i++) {
        int k;
        k = even ? 2*i : 2*i + 1;
        ull count = c(k,Rows);
        mult *= 1ULL*count;

        if (index == C-2) {
            ans += mult;
            ans %= M;
            mult /= count;
            continue;
        }

        cal(nums_rows[index+1] - k, index+1, mult);
        mult /= count;
    }
    return false;
}

void solve()
{
    find_rows();
    cal(nums_rows[0], 0, 1ULL);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {

        cin >> R >> C >> K;
        cin >> S;
        
        memset(check, false, sizeof(check));
        memset(mark, false, sizeof(mark));
        memset(nums_rows, 0, sizeof(nums_rows));
        ans = 0;

        FOR(i,0,K) {
            int x, y;
            cin >> x >> y;
            check[x-1][y-1] = true;
            if (S[y-1] == '+') S[y-1] = '-';
            else S[y-1] = '+';
        }

        int count_negative = 0;
        FOR(i,0,C) {
            if (S[i] == '-') count_negative++;
        }
        if ((count_negative % 2) != 0) {
            cout << 0 << '\n';
            continue;
        }

        solve();
    }

    return 0;
}