#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

int my_code(vector<int> a)
{
        sort(a.begin(), a.end());
        int maxa = a.back();
        int l = 0, r = n-1, mid = -1;
        int fi = -1;
        while (l <= r) {
            mid = (l+r)/2;
            if (a[mid]*2 > maxa) {
                fi = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        int idx = fi-1;
        while (idx >= 0 && (a[fi] + a[idx] > maxa)) idx--;
        return idx+1;
}

int refer_code(vector<int> a)
{
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        // assign 
        for ()
    }
}

long long generate_random_int(long long min, long long max) {
    return min + (rand() % (long long)(max - min + 1));
}

void stress_test(long long size, long long min, long long max) {
    int idx = 1;
    while(1) {
        cout << "Iteration: " << idx << "\n";
        n = generate_random_int(3, 20);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            int tmp = generate_random_int(1, 20);
            a[i] = tmp;
        }
        int my_ans = my_code(a);
        if(my_ans != refer_ans) {
            
        }
        cout << "PASS\n";
        ++idx;
    }
}

signed main() {
    srand(time(0));
    stress_test(100000, 1, 10000000000000);
    return 0;
}