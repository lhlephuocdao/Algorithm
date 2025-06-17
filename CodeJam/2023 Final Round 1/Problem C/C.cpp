#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define pii pair<int, int>
#define sc second
#define fi first
#define all(x) x.begin(), x.end()
const int mod = 998244353;
const int INF = 1e18;

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

// 0-based index
template <typename T>
class SegmentTree {
private:
    int n; // Size of the array
    std::vector<T> tree; // Segment tree array
    std::function<T(T, T)> combine; // Function to combine two segments
    T defaultValue; // Default value for the operation (e.g., 0 for sum, INF for min)

    void build(const std::vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            // Leaf node
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int node, int start, int end, int idx, T value) {
        if (start == end) {
            // Update the leaf node
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    T query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            // Out of range
            return defaultValue;
        }
        if (l <= start && end <= r) {
            // Fully within range
            return tree[node];
        }
        int mid = (start + end) / 2;
        T leftQuery = query(2 * node + 1, start, mid, l, r);
        T rightQuery = query(2 * node + 2, mid + 1, end, l, r);
        return combine(leftQuery, rightQuery);
    }

public:
    SegmentTree(int size, std::function<T(T, T)> combineFunc, T defaultVal)
        : combine(combineFunc), defaultValue(defaultVal)
    {
        n = size;
        tree.resize(4 * size, defaultValue);
    }

    SegmentTree(const std::vector<T>& arr, std::function<T(T, T)> combineFunc, T defaultVal)
        : combine(combineFunc), defaultValue(defaultVal)
    {
        n = arr.size();
        tree.resize(4 * n, defaultValue);
        build(arr, 0, 0, n - 1);
    }

    void update(int idx, T value) {
        update(0, 0, n - 1, idx, value);
    }

    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int32_t main()
{
    fastio;

    int t = 1; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> b(n);
        for (auto& x : b) cin >> x;

        vector<int> v = b;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        // cout << "v: ";
        // for (auto x : v) cout << x << ' ';
        // cout << '\n';

        function<int(int)> getIdx = [&](int x){
            return lower_bound(v.begin(), v.end(), x) - v.begin();
        };

        struct infor {
            int start = 0;
            vector<int> pos;
        };

        unordered_map<int, infor> mp;
        for (int i = 0; i < n; i++)
            mp[b[i]].pos.push_back(i);

        unordered_map<int, set<int>> ms;
        for (int i = 2; i < n; i++)
        {
            int idx = getIdx(b[i]);
            ms[idx].insert(i);
        }

        SegmentTree<int> st1(n, [](int a, int b) { return std::min(a, b); }, INT_MAX);
        SegmentTree<int> st2(n, [](int a, int b) { return std::max(a, b); }, INT_MIN);
        int ans = 0;
        for (int j = 2; j < n; j++)
        {
            int idx = getIdx(b[j]);
            int old = st1.query(idx, idx);
            if (old > j) {
                st1.update(getIdx(b[j]), j);
                // cout << "st1 update " << getIdx(b[j]) << " = " << j << '\n';
            }
        }

        for (int i = 0; i < n; i++) {
            int j1 = 0, j2 = 0;
            // Tìm j nhỏ nhất sao cho b[j] > b[i] (j >= i+2)
            // cout << "b[" << i << "]: " << b[i] << '\n';
            j1 = st1.query(getIdx(b[i])+1, n-1);
            if (j1 != INT_MAX && i+1<n && b[i+1] <= b[i])
                ans += j1 - i +1;

            // cout << "j1: " << j1 << " ans: " << ans << '\n';

            // Chưa tính case b[i] = b[k] với i < k < j
            {
                bool check = (i+1<n && b[i+1] <= b[i]) ? true : false;
                infor& inf = mp[b[i]];
                int& s = inf.start;
                vector<int>& pos = inf.pos;
                int ii = s;
                while (ii < pos.size() && pos[ii] < i) ii++;
                s = ii;
                int prefix = 0;
                // cout << "s: " << s << " j1: " << j1 << " ii: " << ii << '\n';;
                for (; ii < pos.size() && pos[ii] < j1; ii++) {
                    if (check) {
                        ans += (ii - s)*pos[ii] - prefix + (ii - s);
                        prefix += pos[ii];
                        if (ii>0 && pos[ii] - pos[ii-1] == 1) ans -= 2;
                    } else if (pos[ii] > i+1) {
                        s = ii;
                        break;
                    }
                }
                if (check) s = ii;
                // cout << "after s: " << s << '\n';
                // cout << "ans: " << ans << '\n';
            }

            if (i+2 < n) {
                int idx = getIdx(b[i+2]);
                ms[idx].erase(i+2);
                if (!ms[idx].empty()) st1.update(idx, *ms[idx].begin());
                else st1.update(idx, INT_MAX);
            }

            //Tìm j lớn nhất sao cho b[j] > b[i]
            j2 = st2.query(getIdx(b[i]+1), n-1);
            if (j2 != INT_MIN && i-1 >= 0 && b[i-1] <= b[i])
                ans += i - j2 + 1;
            if (i-1 >= 0) {
                int idx = getIdx(b[i-1]);
                int old = st2.query(idx, idx);
                if (old < i-1) st2.update(idx, i-1);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}