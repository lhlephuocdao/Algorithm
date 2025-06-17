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
        // cin >> t;
        while (t--)
        {
            int n; cin >> n;
            vector<int> A(n), B(n);
            vector<int> d(n, 0);
            int sumb = 0;
            for (int i = 0; i < n; i++) {
                cin >> A[i] >> B[i];
                d[i] = A[i] - B[i];
                sumb += B[i];
            }

            sort(d.begin(), d.end());
            vector<int> pre(n+1, 0);
            for (int i = 0; i < n; i++) pre[i+1] = pre[i] + d[i];

            int dA = 0, dB = 0;
            int q; cin >> q;
            while (q--) {
                char c;
                int x;
                cin >> c >> x;
                if (c == 'A')
                    dA += x;
                else
                    dB += x;

                int ans = sumb + n*dB;

                int k = dA - dB;
                auto f = upper_bound(d.begin(), d.end(), -k);
                if (f != d.end()) {
                    int i = f - d.begin();
                    ans += pre[n] - pre[i] + (n-i)*k;
                }
                cout << ans << '\n';
            }
        }

        return 0;
    }