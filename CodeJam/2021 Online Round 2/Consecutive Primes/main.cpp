#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
 
const int maxn = 100000;
vector<int> primes;

void init()
{
    vector<bool> is_prime(maxn+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= maxn; i++) {
        if (is_prime[i] && (long long)i * i <= maxn) {
            for (int j = i * i; j <= maxn; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = 2; i <= maxn; i++)
        if (is_prime[i]) primes.push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;
    cin >> t;

    init();

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> p;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            p.push_back(tmp);
        }

        sort(p.begin(), p.end());

        ll min_ = LONG_LONG_MAX;
        for (int i = 0; i < primes.size()-n; i++)
        {
            ll diff = 0;
            for (int j = 0; j < n; j++)
            {
                diff += abs(p[j] - primes[i+j]);
            }

            min_ = min(min_, diff);
        }

        cout << min_ << '\n';

    }


    return 0;
}