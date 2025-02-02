#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int inf=1000000007;

/* Calculate x^y % mod*/
int power(int x,ll y,int mod)
{
	int t=1;
	while (y)
	{
		if (y&1) t=ll(t)*x%mod;
		x=ll(x)*x%mod;
		y>>=1;
	}
	return t;
}

/* Get */
void gcd(ll a,ll b,ll &x,ll &y)
{
	if (!b) {
		x=1;
		y=0;
		return;
	}

	gcd(b,a%b,y,x);
	y=y-a/b*x;
}

ll inv(ll a,int mod)
{
	ll x,y;
	gcd(a,mod,x,y);
	return (x+mod)%mod;
}

ll sum(ll x,int p)
{
	ll s=0;
	while (x)
	{
		x/=p;
		s+=x;
	}
	return s;
}

int fac(ll x,int p,int k,int mod)
{
	if (!x) return 1;

	int t=1;
	for (int i=1;i<=x%mod;i++)
		if (i%p) t=ll(t)*i%mod;

	t=ll(t)*fac(x/p,p,k,mod)%mod;

	if (x/mod%2&&(p>2||(p==2&&k==2))) 
		t=(mod-t)%mod;

	return t;
}

int calc(ll n,ll m,int p,int k)
{
	int mod=power(p,k,inf);
	int t=ll(fac(n,p,k,mod))*inv(fac(m,p,k,mod),mod)%mod*inv(fac(n-m,p,k,mod),mod)%mod;
	int s=sum(n,p)-sum(m,p)-sum(n-m,p);
	t=ll(t)*power(p,s,mod)%mod;
	return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T;
    cin >> T;
	while (T--)
	{
		ll n,k;
        int m;
        cin >> n >> k >> m;
		/* n: length of a sandwich
		   k: the greatest length of each part
		   m: modulo
		*/

		ll p=(n-1)/k; /* minimum number of sandwiches */
        ll q=(n-1)%k+1;
		if (!p) {
            cout << "1 1\n";
            continue;
        }

		/* m = 324000 = 2^5 * 3^4 * 5^3*/
		int t=m,ans=0;
		for (int i=2;i<=t;i++)
			if (t%i==0)
			{
				int w=1,kk=0;
				while (t%i==0)
				{
					w*=i;
					kk++;
					t/=i;
				}
				/* w = 32
				   kk = 5
				   t = 10125
				*/
				int v=calc(p+k-q,k-q,i,kk);
				ans=(ll(v)*inv(m/w,w)%m*(m/w)%m+ans)%m;
			}
        cout << p+1 << " " << ans << '\n';
	}
	return 0;
}
/* (N/K +R)cR 
	R=K-(N%k)
	7 3 500 -> R = 3 - (7%3) = 2
	(7/3 + 2)C2 = 4C2 = 6
	
	19 3 200 -> R = 3-(19%3) = 2
	(19/3 + 2)C2 = 8C2 = 28
*/
		