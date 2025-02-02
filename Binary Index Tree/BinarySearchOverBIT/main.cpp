#include <bits/stdc++.h>

using namespace std;

void update(vector<long long>& bit, const long long val, long long idx) {
    for(long long i = idx; i < bit.size(); i += i & (-i)) {
        bit[i] += val;
    }
}

long long query(vector<long long>& bit, long long idx) {
    long long sum = 0;
    while(idx > 0) {
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void build_bit(vector<long long>& arr, vector<long long>& bit) {
    long long size = arr.size();
    for(int i = 1; i <= size; ++i) {
        update(bit, arr[i - 1], i);
    }
}

long long sum_binary_search_over_prefix_array(const vector<long long>& arr, const long long val) {
    long long size = arr.size();
    long long left = 1;
    long long right = size;
    long long ans = -1;
    long long m = -1;
    while(left <= right) {
        m = left + ((right - left) / 2);
        long long sum = 0;
        bool is_greater = 1;
        for(int i = 0; i <= (size - m); ++i) {
            if(i > 0) {
                sum = arr[i + m - 1] - arr[i - 1];                
            } else {
                sum = arr[i + m - 1];                
            }
            if(sum > val) {
                is_greater = 0;
                break;
            }
        }
        if(is_greater) {
            ans = m;
            left = m + 1;
        } else {
            right = m - 1;
        }
    }
    return ans;
}

long long bfind(vector<long long>& bit, const long long val) {
    long long left = 1;
    long long right = bit.size() - 1;
    long long ans = -1;
    long long m = -1;
    while(left <= right) {
        m = left + ((right - left) / 2);
        long long sum = 0;
        bool found = 1;
        for(long long i = 0; i < (bit.size() - m); ++i) {
            if(i > 0) {
                sum = query(bit, i + m) - query(bit, i);
            } else {
                sum = query(bit, i + m);
            }
            if(sum > val) {
                found = 0;
                break;
            }
        }
        if(found) {
            ans = m;
            left = m + 1;
        } else {
            right = m - 1;
        }
    }
    return ans;
}

long long generate_random_int(long long min, long long max) {
    return min + (rand() % (long long)(max - min + 1));
}

void show(const vector<long long>& v) {
    long long n = v.size();
    for(long long i = 0; i < n; ++i) {
        std::cout << v[i] <<", ";
    }
    cout << "\n";
}

vector<long long> build_prefix_array(vector<long long>& nums) {
    long long size = nums.size();
    vector<long long> parr(size, 0);
    long long sum = 0;
    for(int i = 0; i < size; ++i) {
        sum += nums[i];
        parr[i] = sum;
    }
    return parr;
}

void stress_test(long long size, long long min, long long max) {
    int i = 1;
    while(1) {
        cout << "Iteration: " << i << "\n";
        long long n = generate_random_int(1, size);
        vector<long long> nums{};
        for(long long i = 0; i < n; ++i) {
            long long num = generate_random_int(min, max + 1);
            nums.push_back(num);
        }
        long long num = generate_random_int(3, size);
        vector<long long> pref(nums);
        vector<long long> ft(nums);
        pref = build_prefix_array(pref);
        vector<long long> bit(nums.size() + 1, 0);
        build_bit(ft, bit);
        long long pans = sum_binary_search_over_prefix_array(pref, num);
        long long bans = bfind(bit, num); 
        if(pans != bans) {
            cout << "Fail: failed not less case\n";
            cout << "\n\narr: ";
            show(nums);
            cout << "num=: " << num << "\n";
            cout << "Approach: prefix array: " << pans << "\n";
            cout << "Approach: BIT=: " << bans << "\n";
            break;
        } 
        cout << "PASS\n";
        ++i;
    }
}

int main() {
    srand(time(0));
    stress_test(100000, 1, 10000000000000);
    return 0;
}