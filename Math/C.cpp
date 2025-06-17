#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
typedef unsigned long long ll;
const int N = 1e5 + 10;
int n, m;
int a[N];
ll has[100010];
int ok[100010], prime[100010], len;
tr1::unordered_map<ll, ll> mp;
tr1::unordered_map<ll, int> id;
void init() {
    for(int i = 2; i <= 100000; i++) {
        if(!ok[i]) {
            prime[len++] = i;
            id[i] = len - 1;
        }
        
        for(int j = 0; j < len && (ll) i * prime[j] <= 100000; j++) {
            ok[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
int main() {
    has[0] = 1;
    for(int i = 1; i <= 100000; i++) 
        has[i] = has[i - 1] * 233;
        
    init();
    ll cnt1, cnt2, ans = 0;
    int num;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt1 = cnt2 = 1;
        for(int j = 0; j <= 400; j++) {
            num = 0;
            if(a[i] % prime[j] == 0) {
                while(a[i] % prime[j] == 0) a[i] /= prime[j], num++;
            }

            num %= m;
            cnt1 = cnt1 + num * has[j]; 
            cnt2 = cnt2 + (m - num) % m * has[j];
        }
        
        if(a[i] != 1) {
            cnt1 = cnt1 + has[id[a[i]]];
            cnt2 = cnt2 + has[id[a[i]]] * (m - 1);
        }
        
        ans += mp[cnt2];
        mp[cnt1]++; 
    }
    
    printf("%lld\n", ans);
    return 0;
} 