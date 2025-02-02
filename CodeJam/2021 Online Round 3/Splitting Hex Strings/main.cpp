#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
 
int dfs(string& s, int index, string prev_val)
{
    if (index == s.length())
        return 1;

    int ans = 0;
    for (int i  = index; i < s.length(); i++)
    {
        string val = s.substr(index, i-index+1);
        if (stoll(val,nullptr,16) >= stoll(prev_val,nullptr,16))
            ans += dfs(s,i+1,val);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        string S;
        cin >> S;
        int ans = dfs(S, 0, "0");
        cout << ans << '\n';
    }
 
    return 0;
}