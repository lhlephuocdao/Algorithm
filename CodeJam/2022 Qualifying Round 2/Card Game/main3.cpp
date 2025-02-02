#include <bits/stdc++.h>

using namespace std;

int n, bob, alice;

int reverseDigits(int num) 
{ 
    int rev_num = 0; 
    while (num > 0) { 
        rev_num = rev_num * 10 + num % 10; 
        num = num / 10; 
    } 
    return rev_num; 
}

void backTracking(int index, vector<int>& V, vector<bool>& mark, int& ans, int current)
{
    if (index == n)
    {
        if (current < bob)
            ans = std::max(ans, current);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (mark[i] == false) {
            mark[i] = true;
            backTracking(index+1, V, mark, ans, current*10 + V[i]);
            mark[i] = false;
        }
    }
}

void solve()
{
    cin >> n >> bob >> alice;
    bob = std::min(bob, reverseDigits(bob));
    vector<int> A;
    while (alice > 0)
    {
        A.push_back(alice%10);
        alice /= 10;
    }
    sort(A.begin(), A.end(), greater<int>());
    vector<bool> mark(n, false);
    int ans = INT_MIN;
    backTracking(0, A, mark, ans, 0);

    if (ans == INT_MIN) {
        ans = 0;
        for (int i = 0; i < n-1; i++)
            ans = ans*10 + A[i];
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}