#include<bits/stdc++.h>
using namespace std;
#define ll int
void calc(set<tuple <ll, ll, ll> > &sa, string &s, int n) {
    vector <ll> a(3), m(3);

    for(int i = 0; i <= n; i++)
        if(s[i] == 'R') s[i] = 0;
        else if(s[i] == 'G') s[i] = 1;
        else s[i] = 2;

        for(int i = 0; i < n; i++)
            if(s[i]  == s[i+1])
                a[s[i]]++;
    
    sa.insert({a[0], a[1], a[2]});
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 3; j++) {
            if(s[i] != j) {
                m[0] = a[0]; m[1] = a[1]; m[2] = a[2]; 
                if(i > 0) {
                    if(s[i] == s[i-1]) m[s[i]]--;
                    if(j == s[i-1]) m[j]++;
                }
                if(i < n) {
                    if(s[i] == s[i+1]) m[s[i]]--;
                    if(j == s[i+1]) m[j]++;
                }
                sa.insert({m[0], m[1], m[2]});
            }
        }
}

void resolve() {
    int X, Y, Z;
    set<tuple <int, int, int> > sa, sb, sc;
    string sx, sy, sz;
    cin >> X  >> Y >> Z;
    cin >> sx >> sy >> sz;

    calc(sa, sx,X);
    calc(sb, sy,Y);
    calc(sc, sz,Z);

    long long res = 0, tmp = 0;
    for(auto [i0, i1, i2] : sa)
        for(auto [j0, j1, j2] : sb)
            for(auto [k0, k1, k2]: sc) {
                tmp = (long long) i0* j1*k2 + (long long) i0*j2*k1 + (long long) i1* j0*k2 + (long long) i1*j2*k0 + (long long) i2* j1*k0 + (long long) i2*j0*k1;
                if(tmp > res)
                res = tmp;
            }
    cout << res << "\n"; 
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    int T;
    cin >> T;
    while (T--) {
        resolve();
    }

    return 0;
}