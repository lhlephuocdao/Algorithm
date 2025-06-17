#include<bits/stdc++.h>
using namespace std;
#define mxn 100005
int seg[4*mxn];
void update(int st, int l, int r, int idx, int val){
    if(l == r){
        seg[st] = val;
        return;
    }
    int mid = (l + r)/2;
    if(idx <= mid)
        update(2*st, l, mid, idx, val);
    else
        update(2*st+1, mid+1, r, idx, val);
    seg[st] = min(seg[2*st], seg[2*st+1]);
}
int mex_query(int st, int l, int r, int val){
    if(l == r)
        return l;
    int mid = (l + r)/2;
    if(seg[2*st] < val)
        return mex_query(2*st, l, mid, val);
    return mex_query(2*st+1, mid+1, r, val);
}
int xr_range(int n){
    if(n%4 == 0)
        return n;
    if(n%4 == 1)
        return 1;
    if(n%4 == 2)
        return n+1;
    return 0;
}
int cal(int num){
    if(num == 0)
        return 0;
    if(num%2 == 0){
        return 2*xr_range(num/2);
    }
    return (xr_range(num+1)^(2*xr_range((num+1)/2)));
}
vector<int> solve (int N, int Q, vector<int> A, vector<vector<int> > query) {
    // Write your code here
    for(int i = 0; i <= 4*(N+2) ; i++)
        seg[i] = 0;
    vector<pair<int, int>> nq[N+1];
    int i;
    for(i = 0; i < Q ; i++){
        nq[query[i][1]].push_back({query[i][0], i});
    }
    for(i = 1 ; i <= N ; i++)
        sort(nq[i].begin(), nq[i].end());
    // Fix 'r', find smallest 'x' such that last[x] < l
    vector<int> ans(Q);
    for(i = 1 ; i <= N ; i++){
        cout << "update: index A[i-1]: " << A[i-1] << " val: " << i << '\n';
        update(1, 1, N+1, A[i - 1], i);
        for(auto j : nq[i]){
            int l = j.first, idx = j.second;
            // num : 
            int num = mex_query(1, 1, N+1, l) - 1;
            cout << "l: " << l << " r: " << i << " idx: " << idx << " num: " << num << '\n';
            ans[idx] = cal(num); // min val < l
        }
    }
    sort(A.begin(), A.end());
    for(i = 0; i < N ; i++)
        assert(A[i] == i + 1);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    assert(1 <= T && T <= 10);
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        assert(1 <= N && N <= 1e5);
        int Q;
        cin >> Q;
        assert(1 <= Q && Q <= 1e5);
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
          cin >> A[i_A];
            assert(1 <= A[i_A] && A[i_A] <= N);
        }
        vector<vector<int> > query(Q, vector<int>(2));
        for (int i_query = 0; i_query < Q; i_query++)
        {
          for(int j_query = 0; j_query < 2; j_query++)
          {
            cin >> query[i_query][j_query];
          }
        }

        vector<int> out_;
        out_ = solve(N, Q, A, query);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
          cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}