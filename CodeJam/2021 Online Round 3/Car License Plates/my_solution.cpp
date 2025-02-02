#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
 
string process(string source, int& count)
{
    string ans = source;
    for (int i = 0; i < ans.length(); i++)
    {
        char s = ans[i];
        if (s >= 'A' && s <= 'Z') {
            count++;
            ans[i] += 32; 
        }
    }

    sort(ans.begin(), ans.end());
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
        int n,k;
        cin >> n >> k;
    
        unordered_map<int, vector<string>> m;

        for (int i = 0; i < n; i++)
        {  
            string tmp;
            cin >> tmp;

            int count = 0;
            string ret = process(tmp, count);
            // cout << "count: " << count << " ret: " << ret << '\n';
            m[count].push_back(ret);
        }

        ll ans = 0;
        for (auto itr : m)
        {
            vector<string> v = itr.second;
            unordered_map<string, int> mm;
            for (auto i : v) {
                mm[i]++;
            }

            for (auto x : mm) {
                int c = x.second;
                ans += 1LL*(c*(c-1))/2;
            }
        }

        cout << ans << '\n';

    }
 
    return 0;
}
