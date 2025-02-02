#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define ll long long
 
int F,W,L, _n; // num
const int MAX_SIZE = 16;
int _distance [MAX_SIZE][MAX_SIZE]; // _distance
int _memory [MAX_SIZE][1<<MAX_SIZE]; // for memoization
vector<pair<pair<int,int>, int>> V;

void getInput() {
    cin >> F >> W >> L >> _n;
    V.clear();
    memset(_memory, 0, sizeof(int) * MAX_SIZE * (1<<MAX_SIZE));
    memset(_distance, 0, sizeof(int) * MAX_SIZE * MAX_SIZE);

    for (int i = 0; i < _n+1; i++)
    {
        int z,x,y;
        cin >> z >> x >> y;
        V.push_back(make_pair(make_pair(x,y), z));
    }
}

    /* x,y,z : source */
    /* xx,yy,zz: destination */
int find(int x, int y, int z, int xx, int yy, int zz)
{
    int d1 = (x-1 + y-1) + (xx-1 + yy-1);
    int d2 = (W-x + y-1) + (W-xx + yy-1);
    int d3 = (x-1 + L-y) + (xx-1 + L-yy);
    int d4 = (W-x + L-y) + (W-xx + L-yy);
    int dmin = d1;
    if (d2 < dmin) dmin = d2;
    if (d3 < dmin) dmin = d3;
    if (d4 < dmin) dmin = d4;

    if (z > zz) dmin += (z-zz);
    else dmin += (zz-z)*2;

    return dmin;
}

void cal()
{
    for (int i = 0; i < _n+1; i++) {
        for (int j = 0; j < _n+1; j++) {
            if (i == j) _distance[i][j] = 0;
            else {
                int xi = V[i].first.first;
                int yi = V[i].first.second;
                int zi = V[i].second;
                
                int xj = V[j].first.first;
                int yj = V[j].first.second;
                int zj = V[j].second;

                if (zi == zj) {
                    _distance[i][j] = abs(xi-xj) + abs(yi-yj);
                } else {
                    /* (1,1), (W,1), (1,L), (W,L) */
                        /*   1      2      3      4   */
                    _distance[i][j] = find(xi,yi,zi,xj,yj,zj);
                }
            }
        }
    }
}

void show()
{
    for (int i = 0; i < _n+1; i++) {
        for (int j = 0; j < _n+1; j++) {
            cout << _distance[i][j] << " ";
        }
        cout << '\n';
    }
}

int tsp (int from, int toFlag) {
    int &memo = _memory[from][toFlag];
    if (memo != 0) {
        return memo;
    }
    if (__builtin_popcount(toFlag) == 1) {  
        int to = __builtin_ctz(toFlag);
        return _distance[from][to];
    }
 
    memo = INT_MAX;
    for (int i = 0; i < _n+1 /* the nuber of cities */; i++) {
        if (!(toFlag & (1 << i))) continue;
 
        int v = _distance[from][i] + tsp(i, (toFlag & ~(1<<i)));
        memo = min(memo, v);
    }
    return memo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        getInput();
        cal();
        int m = INT_MAX;
        int allFlag = (1<<_n+1) - 1;
        int v = tsp(0, allFlag & ~(1<<0));
        m = min(m, v);
        cout << m << endl;
    }

    return 0;
}