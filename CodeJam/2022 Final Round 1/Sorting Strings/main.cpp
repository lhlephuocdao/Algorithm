#include <bits/stdc++.h>

using namespace std;

const int maxn = 15000 + 7;
int n;
vector<string> v;

bool compare(const string& a, const string& b)
{
    int n1 = a.length();
    int n2 = b.length();

    int i=0, j=0;
    while(i<n1 && j<n2)
    {
        char s1 = a[i];
        char s2 = b[j];

        if (s1 == '-' && s2 != '-') return false;
        else if (s1 != '-' && s2 == '-') return true;

        if (s1 == s2) {
            i++; j++;
            continue;
        } else {
            int sa = s1;
            int sb = s2;
            int lower_sa = tolower(sa); 
            int lower_sb = tolower(sb);

             if (lower_sa == lower_sb) {
                if (isupper(sa) && islower(sb)) return true;
                else if (islower(sa) && isupper(sb)) return false;
             } else {
                return lower_sa < lower_sb;
             }
        }
    }

    if (i == n1) return true;
    else if (j==n2) return false;

    return true;
}

void solve()
{
    cin >> n;
    v.clear();
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), compare);
    for (auto s : v) cout << s << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}