#include <bits/stdc++.h>
using namespace std;
 
const int blockSZ = 400 ;
int N , Q , tree[80][10000+10] , arr[30000+10] ;

void update(int b, int x, int delta){
  for(int i = x; i <= 10000; i += i & -i)
    tree[b][i] += delta;
}

int query(int block, int k) {
    int sum = 0, idx = k;
    while (idx > 0) {
        sum += tree[block][idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

int query(int block, int l, int r) {
    return query(block, r) - query(block, l-1);
}
  
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> N;
  
    for(int i=1;i<=N;i++)
    {
        cin >> arr[i];
        update(i/blockSZ,arr[i],1);
    }
  
    cin >> Q;
  
    while( Q-- )
    {
        int flag ;
        cin >> flag;
        if(flag==0)
        {
            int i , v ;
            cin >> i >> v;
            update(i/blockSZ,arr[i],-1);
            update(i/blockSZ,v,1);
            arr[i] = v ;
        }
        else
        {
            int L , R , k ;
            cin >> L >> R >> k;
            int ans = 0 ;
  
            while(L<=R&&L%blockSZ!=0) ans+= arr[L++]>k ;
            while(L<=R&&R%blockSZ!=blockSZ-1) ans+=arr[R--]>k ;
  
            if(L<R)
            {
                int bl = L/blockSZ ;
                int br = R/blockSZ ;
                for(int i=bl;i<=br;i++) ans+= query(i, k+1, 10000);
            }
  
            cout << ans << '\n';
        }
    }
  
    return 0;
}