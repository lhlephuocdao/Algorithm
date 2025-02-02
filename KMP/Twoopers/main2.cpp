#include <stdio.h>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define problem TWOOPERS
#define superCoder Kviss Cooler
 
string S,T;
int N = 0;
char P[400001];
int Pre[400001],Post[400001];
int L,R;
 
void Add_String(string str){
    for(int i = 0; i < str.size(); ++i) P[++N] = str[i];
}
 
void FindPre(int i,int v){
    v = max(v,i);
    while(v <= N && P[v] == P[v - i + 1]) ++v;
    Pre[i] = v - i;
    if(v - 1 > R){
        L = i;
        R = v - 1;
    }
}
void FindPost(int i,int v){
    v = min(v,i);
    while(v > 0 && P[v] == P[N - i + v]) --v;
    Post[i] = i - v;
    if(v + 1 < L){
        L = v + 1;
        R = i;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //freopen("TWOOPERS.INP","r",stdin);
    //freopen("TWOOPERS.OUT","w",stdout);
 
    cin >> S >> T;
 
    int M = S.size();
 
    Add_String(T);
    Add_String(S);
    Add_String(S);
    Add_String(T);
 
    // Init Prefix Arr
 
    Pre[1] = 0;
    L = R = 0;
    for(int i = 2; i <= N; ++i){
        if(i >= R) FindPre(i,i);
        else{
            int a = i - L + 1;
            int b = R - L + 1;
            if(i + Pre[a] - 1 < R) Pre[i] = Pre[a];
            else FindPre(i,R + 1);
        }
    }
 
    Post[N] = 0;
    L = R = N + 1;
    for(int i = N - 1; i > 0; --i){
        if(i <= L) FindPost(i,i);
        else{
            int a = R - i + 1;
            int b = R - L + 1;
            a = N - a + 1;
            b = N - b + 1;
            if(i - Post[a] + 1 > L) Post[i] = Post[a];
            else FindPost(i,L - 1);
        }
    }
 
    long long res = 0;
 
    for(int i = 1; i <= M; ++i){
        int x = Pre[i + M] + Post[i + 2*M - 1];
        if(x >= M) res += M;
        else if(x == M - 1) res += 1;
    }
 
    cout << res;
 
    return 0;
}