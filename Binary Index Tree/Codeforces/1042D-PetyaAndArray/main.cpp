#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=6e5+7;
typedef long long LL;
LL m,n,k,x,y,z;
LL t,a[maxn],b[maxn],c[maxn];
//int getid(int x){
//    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
//}

LL lowbit(LL x){
    return x&(-x);
}
LL query(LL x){
    LL ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void add(LL x){
    while(x<=n+1){
        c[x]++;
        x+=lowbit(x);
    }
}
int main(){
    scanf("%lld%lld",&n,&t);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
        b[i]=a[i];
    }
    sort(b,b+n+1);
    LL ans=0;
    /*
    i:   0 1 2 3 4  5
    	   5 -1 3 4 -1
    cnt:   
    a[]: 0 5 4 7 11 10
    b[]: 0 4 5 7 10 11
    */

    for(int i=1;i<=n;i++){
    	LL xx = lower_bound(b,b+n+1,a[i-1])-b+1; // xx: số phần tử mảng cộng dồn <= a[i-1] -> pref[L-1]
        add(xx); // c[3]++ 
        LL yy = lower_bound(b, b + n + 1, a[i] - t + 1) - b;// : số phần tử mảng cộng dồn 
        LL q = query(yy); // số subarrays mà có tổng >= t
        ans+=(i - q);
        cout << "i: " << i << " xx: " << xx << " yy: " << yy << " q: " << q << " ans: " << ans << '\n';
    }
    printf("%lld\n",ans);
    return 0;
}

 		   	 		 	 		   	 			