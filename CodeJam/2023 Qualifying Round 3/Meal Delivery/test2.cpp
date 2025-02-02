#include <iostream>
#include <cstring>
using namespace std;
 
 
int _n; // num
const int MAX_SIZE = 15; // Enough (can't be more than 32) depending on input size
int _distance [MAX_SIZE][MAX_SIZE]; // _distance
int _memory [MAX_SIZE][1<<MAX_SIZE]; // for memoization
 
 
  
void getInput() {
    cin >> _n;
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _n; j++) {
            cin >> _distance[i][j];
        }
    }
    memset(_memory, 0, sizeof(int) * MAX_SIZE * (1<<MAX_SIZE));
}
 
  
int tsp (int from, int toFlag) {
    int &memo = _memory[from][toFlag]; // _memory[][] must be initialized to 0.
    if (memo != 0) {
        return memo;
    }
    if (__builtin_popcount(toFlag) == 1) {  //count the number of one’s(set bits) in an integer. 
        int to = __builtin_ctz(toFlag);     //count the trailing zeros of the given integer
        return _distance[from][to];
    }
 
    memo = INT_MAX; // You can just use a large enough number
    for (int i = 0; i < _n /* the nuber of cities */; i++) {
        if (!(toFlag & (1 << i))) continue;
 
        int v = _distance[from][i] + tsp(i, (toFlag & ~(1<<i)));
        memo = min(memo, v);
    }
    return memo;
}
  
int main() {
    getInput();
    int m = INT_MAX;
    int allFlag = (1<<_n) - 1; // = 15 = 1111
    // for (int i = 0; i < _n; i++) {
        int v = tsp(0, allFlag & ~(1<<0));
        m = min(m, v);
    // }
    cout << m << endl;
    return 0;
}