#include <bits/stdc++.h>
using namespace std;

static const int MOD = 987654323;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        long long m = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            m += v[i];
        }

        // Quick feasibility: no type may exceed (m+1)/2
        int mx = *max_element(v.begin(), v.end());
        if (mx > (m + 1) / 2) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        // Max‐heap of (remaining count, type)
        priority_queue<pair<int,int>> pq;
        set<int> avail;
        for (int i = 0; i < n; i++) {
            if (v[i] > 0) {
                pq.emplace(v[i], i);
                avail.insert(i);
            }
        }

        long long answer = 0;
        int last = -1;
        bool bad = false;

        for (long long i = 1; i <= m; i++) {
            // Clean stale heap‐tops
            while (!pq.empty() && pq.top().first != v[pq.top().second]) {
                pq.pop();
            }
            if (pq.empty()) {
                bad = true;
                break;
            }

            auto [cntTop, typeTop] = pq.top();
            long long rem = m - i + 1;
            int pick = -1;

            // If this type exactly fills half+½ of the remaining slots, we must pick it now
            if ((rem % 2 == 1) && cntTop == (rem + 1) / 2) {
                if (typeTop == last) {
                    bad = true;
                    break;
                }
                pick = typeTop;
                pq.pop();
            } else {
                // Otherwise pick the smallest available ≠ last
                auto it = avail.begin();
                if (it != avail.end() && *it == last) ++it;
                if (it == avail.end()) {
                    bad = true;
                    break;
                }
                pick = *it;
                if (pick == typeTop) {
                    pq.pop();
                }
            }

            // Accumulate weighted sum
            answer = (answer + (i * (long long)(pick + 1)) % MOD) % MOD;

            // Decrement and update structures
            v[pick]--;
            if (v[pick] == 0) {
                avail.erase(pick);
            } else {
                pq.emplace(v[pick], pick);
            }
            last = pick;
        }

        if (bad) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << answer << "\n";
        }
    }

    return 0;
}
