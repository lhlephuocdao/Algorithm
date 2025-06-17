#include <bits/stdc++.h>
using namespace std;

const int MAX = 21;
int N, M;
int a[MAX], b[MAX], l[1<<MAX], f[1<<MAX];
 
void solve(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }
    for(int i=0; i<M; i++){
        cin >> b[i];
    }
    memset(f, -1, sizeof(f));
    memset(l, 0, sizeof(l));
    f[0] = 0;
    // f[s] : number of people that can be covered by subset s
    // f[0] : can cover 0 people by empty subset
    // l[s] : sum of banknotes which is not used yet in subset s
 
    for(int mask=0; mask < (1<<M); mask++)
        if(f[mask] != -1){
            for(int i=0; i < M; i++)
                if(!(mask & (1<<i))){ // i is not included in subset mask
                    int x = b[i] + l[mask];
                    if(x < a[f[mask] + 1]){
                        f[mask | (1<<i)] = f[mask];
                        l[mask | (1<<i)] = x;
                    }
                    else if(x == a[f[mask] + 1]){
                        f[mask | (1<<i)] = f[mask] + 1;
                        l[mask | (1<<i)] = 0;
                    }

                    if(f[mask | (1<<i)] == N){
                        cout << "YES\n";
                        return;
                    }
                }
        }
 
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
	return 0;
}