#include <bits/stdc++.h>
using namespace std;

int n,m,x,nn;
long long ans = 0;
vector<vector<int>> g(13);
vector<vector<pair<int, int>>> c(13);
vector<int> idx(13), rev(13);

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

bool check(int pos, vector<int>&nums, int k)
{
    for (auto i : c[idx[pos]]) {
        int j = i.first;
        int g = i.second;
        if (j > idx[pos]) continue;
        if (gcd(k, nums[rev[j]-1]) != g) return false;
    }
    return true;
}

void backtrack(int pos, vector<int>& a, vector<int>& nums)
{
    if (pos > nn) {
        if (nums.size() == nn) {
            ans++;
        }
        return;
    }

    for (int i = 0; i < g[a[idx[pos]]].size(); i++)
    {
        int k = g[a[idx[pos]]][i];
        if (k > x) break;
        if (check(pos, nums, k) == false) continue;

        nums.push_back(k);
        backtrack(pos+1, a, nums);
        nums.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> x;
    for (int i = 1; i <= 12; i++)
    {
        int j = i;
        while (j <= 12)
        {
            g[i].push_back(j);
            j += i;            
        }
    }

    vector<int> a(n+1, 1);
    for (int k = 0; k < m; k++)
    {
        int i,j,g;
        cin >> i >> j >> g; // gcd(a[i], a[j]) = g
        a[i] = lcm(a[i], g);
        a[j] = lcm(a[j], g);
        c[i].push_back({j, g});
        c[j].push_back({i, g});
    }

    int i = 1, j = 1;
    while (i <= n)
    {
        if (a[i] == 1) {
            i++;
            continue;
        }

        idx[j] = i;
        rev[i] = j;
        j++;
        i++;
    }

    int diff = i-j;
    nn = n - diff;


    vector<int> nums;
    backtrack(1, a, nums);
    if (diff > 0) {
        for (int i = 1; i <= diff; i++)
            ans *= x;
    }
    
    cout << ans << '\n';

    return 0;
}