#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, L, U;
    cin >> N >> L >> U;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    map<int, int> m;

    function<ll(int)> fn = [&](int x){
        m.clear();
        int count = 0;
        ll ans = 0;
        for (int l = 1, r = 1; r <= N; r++)
        {
            m[a[r]]++;
            if (m[a[r]] == 1) count++;
            while (count > x)
            {
                if (m[a[l]] == 1) {
                    m.erase(a[l]);
                    count--;
                } else m[a[l]]--;
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    };

    cout << fn(U) - fn(L-1) << '\n';

    return 0;
}