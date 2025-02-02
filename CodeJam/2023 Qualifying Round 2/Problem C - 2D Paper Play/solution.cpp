#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <random>
using namespace std;
 
class FenwickTree {
private:
    vector<int> tree;
    int n;
 
public:
    FenwickTree(int size) {
        n = size;
        tree.resize(n + 1, 0);
    }
 
    void update(int i, int delta) {
        while (i <= n) {
            tree[i] += delta;
            i += (i & -i);
        }
    }
 
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }
 
    int range_query(int i, int j) {
        return query(j) - query(i - 1);
    }
};
 
 
void countBigger(vector<pair<int,int>>& list /*paper*/, vector<pair<int,int>>& query /*block*/, vector<int>& result) {
     
    // Find the maximum values of x and y in the input pairs
    int max_y = 0;
    for(auto p : list) {
        max_y = max(max_y, p.second);
    }
    for(auto p : query) {
        max_y = max(max_y, p.second);
    }
    max_y++;
 
    FenwickTree ft(max_y);
    sort(list.begin(), list.end(), [] ( const pair<int,int>& a, const pair<int,int>& b){
        return a.first > b.first;
    });
    cout << "max_y: " << max_y << "\n"; 
    for (auto it : list)
        cout << it.first << " " << it.second << "\n";
    
    sort(query.begin(), query.end(), [] ( const pair<int,int>& a, const pair<int,int>& b){
        return a.first > b.first;
    });
    for (auto it : query)
        cout << it.first << " " << it.second << "\n";

    int p = 0;
    for(int i=0;i< query.size();i++) {
        while( p < list.size() && list[p].first >= query[i].first){
            ft.update(list[p].second, 1 );
            p++;
        }
        result.push_back(ft.range_query(query[i].second, max_y));
    }
     
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int sum[50001];
    while(t--){
         
        int n,m,q;
        cin >> n >> m >> q;
        vector<pair<int,int>> block(n);
        vector<pair<int,int>> paper(m);
    
        for(int i=0;i<n;i++) {
            cin >> block[i].first >> block[i].second;
    
        }
        for(int i=0;i<m;i++) {
            cin >> paper[i].first >> paper[i].second;
        }
        vector<int> c;
        countBigger(paper, block,c);
        for (auto it : c) 
            cout << it << " ";
        cout << '\n';

        sort(c.begin(), c.end());
        //vector<int> sum(m+1, 0);
        int p = 0;
        for(int i=0;i<= m;i++) {
            while(p < c.size() && c[p] < i)
                p++;
            sum[i] = n- p;
            cout << "sum[" << i << "]: " << sum[i] << " p: " << p << '\n';
        }
        sum[m+1] = 0;
        for(int i=0;i<q;i++) {
            int a,b;
            cin >> a >> b;
            cout << sum[a] - sum[b+1] << " ";
        }
        cout << endl;
    }
    return 0;
}