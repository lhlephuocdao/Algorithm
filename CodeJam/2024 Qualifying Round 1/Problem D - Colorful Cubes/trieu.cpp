#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
//#include<pair>
using namespace std;

void calc(set<vector<long long>> &sa, string &s, int n) {
    vector<long long> a(3);

    for(int i = 0; i <= n; i++)
        //convert RGB -> 123
        if(s[i] == 'R') s[i] = 0;
        else if(s[i] == 'G') s[i] = 1;
        else s[i] = 2;

        for(int i = 0; i < n; i++)
            if(s[i]  == s[i+1])
                a[s[i]]++;
    
    sa.insert(a);
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 3; j++) {
            if(s[i] != j) {
                vector<long long> m(a);
                if(i > 0) {
                    if(s[i] == s[i-1]) m[s[i]]--;
                    if(j == s[i-1]) m[j]++;
                }
                if(i < n) {
                    if(s[i] == s[i+1]) m[s[i]]--;
                    if(j == s[i+1]) m[j]++;
                }
                sa.insert(m);
            }
        }
}

void resolve() {
    int X, Y, Z;
    set<vector<long long>> sa, sb, sc;
    string sx, sy, sz;
    cin >> X  >> Y >> Z;
    cin >> sx >> sy >> sz;

    calc(sa, sx,X);
    calc(sb, sy,Y);
    calc(sc, sz,Z);

    long long res = 0, tmp;
    for(const vector<long long> &i: sa)
        for(const vector<long long> &j: sb)
            for(const vector<long long> &k: sc) {
                tmp = i[0]* j[1]*k[2] + i[0]*j[2]*k[1] + i[1]* j[0]*k[2] + i[1]*j[2]*k[0] + i[2]* j[1]*k[0] + i[2]*j[0]*k[1];
                if(tmp > res)
                res = tmp;
            }
    cout << res << endl; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        resolve();
    }

    return 0;
}