#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define int long long
#define pii pair<int, int>

// directions: 0=up, 1=right, 2=down, 3=left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

/*
 * stuff you should look for
 * [Before Submission]
 * array bounds, initialization, int overflow, special cases (like n=1), typo
 * [Still WA]
 * check typo carefully
 * casework mistake
 * special bug :
 *      - duplicated element
 *      - consecutive range: 1 2 3 4 5 ....
 * stress test
 */

int32_t main()
{
    fastio;

    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        int cnt = 0;
        int same = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                cnt++;
                same = i;
            }
        }

        if ((cnt==1 && n%2==0) || cnt>1) {
            cout << -1 << '\n';
            continue;
        }

        vector<bool> ok(n, false);
        int diff = n;
        for (int i = 0; i < n; i++)
            if (a[i] == b[n-i-1])
            {
                ok[i] = true;
                diff--;
            }

        vector<pii> ans;

        // handle same
        int mid = n/2;
        int k = 0;
        // cout << "same: " << same << '\n';
        if (same != -1 && same != mid) {
            // swap same <-> mid
            swap(a[same], a[mid]);
            swap(b[same], b[mid]);
            k++;
            ans.push_back({same+1, mid+1});
            diff--;
            ok[mid] = true;

            if (a[same] == b[n-same-1] && ok[same] == false) {
                diff--;
                ok[same] = true;
            }

            if (b[same] == a[n-same-1] && ok[n-same-1] == false) {
                diff--;
                ok[n-same-1] = true;
            }
        }

        vector<int> id(n+1);
        for (int i = 0; i < n; i++)
            id[b[i]] = i;

        // for (auto x : id) cout << x << ' ';
        // cout << '\n';

        for (int i = 0; i < n; i++)
        {
            if (ok[i]) continue;

            // need swap a[i] <-> a[id[a[i]]]
            int j1 = id[a[i]];
            int j2 = n-1-i;
            int b1 = b[j1];
            int b2 = b[j2];
            // cout << "i: " << i << " j1: " << j1 << " j2: " << j2 << '\n';
            swap(a[j1], a[j2]);
            swap(b[j1], b[j2]);
            swap(id[b1], id[b2]);
            ans.push_back({j1+1, j2+1});
            k++;
            diff--;
            ok[i] = true;

            // check a[j1] and b[n-1-j1]
            if (ok[j1] == false && a[j1] == b[n-1-j1]) {
                ok[j1] = true;
                diff--;
            }

            // check b[j1] and a[n-1-j1]
            if (ok[n-1-j1] == false && a[n-1-j1] == b[j1]) {
                ok[n-1-j1] = true;
                diff--;
            }

            //check a[j2] and b[n-1-j2]
            if (ok[j2] == false && a[j2] == b[n-1-j2]) {
                ok[j2] = true;
                diff--;
            }

            if (k > n) break;
        }

        if (k>n) {
            cout << -1 << '\n';
        } else {
            bool pos = true;
            for (int i = 0; i < n; i++)
                if (a[i] != b[n-1-i])
                    pos = false;

            if (!pos)
                cout << -1 << '\n';
            else {
                cout << k << '\n';
                for (auto x : ans)
                    cout << x.first << ' ' << x.second << '\n';
            }
        }
    }
    return 0;
}