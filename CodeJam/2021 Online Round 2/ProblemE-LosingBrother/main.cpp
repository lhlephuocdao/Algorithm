#include <bits/stdc++.h>

using namespace std;

const int maxn = 157;
const string albert = "ALBERT";
const string alice = "ALICE";

string s = "";
bool check[maxn][maxn][250];
int ans = INT_MAX;
const int OFFSET = 75;

void calc(int left, int right, int diff, bool is_albert)
{
    if (left > right) {
        if (diff > 0) ans = std::min(diff, ans);
        check[left][right+1][diff+OFFSET] = true;
        return;
    }

    if (check[left][right+1][diff+OFFSET] == true) return;

    if (is_albert) {
        if (albert.find(s[left]) != string::npos) {
            /* leftmost card gives 2 points */
            calc(left+1, right, diff+2, false);
        } else {
            if (albert.find(s[right]) != string::npos) {
                /* rightmost card gives 2 points */
                calc(left, right-1, diff+2, false);
            } else {
                /* neither of the two cards give points */
                calc(left, right-1, diff, false);
            }
        }
    } else {
        /* Alice takes the leftmost card */
        if (alice.find(s[left]) != string::npos)
            calc(left+1, right, diff-1, true);
        else
            calc(left+1, right, diff, true);

        /* Alice takes the rightmost card */
        if (alice.find(s[right]) != string::npos) {
            calc(left, right-1, diff-1, true);
        }
        else
            calc(left, right-1, diff, true);
    }
    check[left][right+1][diff+OFFSET] = true;
}

void solve()
{
    cin >> s;
    ans = INT_MAX;
    memset(check, false, sizeof(check));
    int n = s.size();
    calc(0, n-1, 0, true);
    if (ans == INT_MAX) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}