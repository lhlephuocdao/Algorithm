#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
 
int getParent(vector<int>& par, int node) {
    if( par[node] == node)
        return node;
    par[node] = getParent(par, par[node]);
    return par[node];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long a, b, s;
        cin >> n >> s >> a >> b;
        unordered_set<int> st;
        vector<int> par(n);
        for(int i=0;i<n;i++)
            par[i] = i;

        int cnt = 0, edge = 0;
        long long e;
        while (true) {
            cnt++;
            if (cnt == 1) {
                e = s % (n * n);
            } else {
                e = (e * a + b) % (n * n);
            }
            int x = e / n;
            int y = e % n;
            if (st.find(e) != st.end()) {
                cout << "0" << endl;
                break;
            }
            int par_a = getParent(par, x);
            int par_b = getParent(par, y);
            if(par_a != par_b) {
                par[par_a] = par_b;
                edge++;
            }
            if( edge == n-1) {
                cout << cnt << endl;
                break;
            }
            st.insert(e);
        }
    }
    return 0;
}