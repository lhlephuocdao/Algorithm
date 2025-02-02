#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
#define ull unsigned long long
#define M 1000000007

ll fact[50000];

void init()
{
    fact[0] = 1;
    fact[1] = 1;

    for (int i = 2; i <= 50000; i++)
    {
        fact[i] = (1LL * i * fact[i-1]) % M;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    // init();
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n,m;
        scanf("%d%d", &n, &m);

        int A[n], count[n];
        memset(count, 0, sizeof(count));

        FOR(i,0,n)
            scanf("%d", &A[i]);

        int X[m], Y[m], diff[n+1];
        memset(diff, 0, sizeof(diff));
        FOR(j,0,m)
        {
            scanf("%d%d", &X[j], &Y[j]);
            diff[X[j]-1]++;
            diff[Y[j]]--;
        }

        sort(A, A+n, greater<int>());

        count[0] = diff[0];
        FOR(i,1,n) {
            count[i] = count[i-1] + diff[i]; 
        }

        sort(count, count+n, greater<int>());

        ll sum = 0, nums = 1;
        int pre = -1, length = 0;
        FOR(i,0,n) {
            int a = A[i], c = count[i];
            sum += 1LL*a*c;

            if (pre != c) {
                length = 1;
                pre = c;
            } else length++;

            nums *= length;
            nums %= M;
        }

        printf("%lld %lld\n", sum, nums);
    }

    return 0;
}