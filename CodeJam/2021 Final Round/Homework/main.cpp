#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int n, S;
        cin >> n >> S;

        int t[n], v[n];
        FOR(i,0,n)
            cin >> t[i];

        FOR(i,0,n)
            cin >> v[i];

        vector<pair<int, int>> V;
        FOR(i,0,n)
            V.push_back(make_pair(t[i], v[i]));
        sort(V.begin(), V.end());

        priority_queue<pair<int, int>> Q;
        int curr_index = 0, curr_time = S; 
        for (int i = 0; i < n && V[i].first <= S; i++) {
            curr_index = i;
            Q.push(make_pair(V[i].second, V[i].first));
        }

        ll ans = 0;

        while (true) {
            if (Q.empty() && curr_index < n-1) {
                curr_index++;
                Q.push(make_pair(V[curr_index].second, V[curr_index].first));
                curr_time = V[curr_index].first;
            }

            while (curr_index < n-1 && curr_time >= V[curr_index+1].first) {
                curr_index++;
                Q.push(make_pair(V[curr_index].second, V[curr_index].first));
            }

            if (Q.empty()) break;

            pair<int, int> q = Q.top();
            Q.pop();
            ans += 1LL*q.first*(curr_time - q.second);
            curr_time++;
        }

        cout << ans << "\n";
    }
 
    return 0;
}