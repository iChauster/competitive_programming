//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

int check(int num, vector<int> v) {
    long long i = 0;
    long long j = v.size() - 1;
    int ret = 0;
    while (i < j) {
        long long sum = v[i] + v[j];
        if (sum != num){
            if (sum > num) {
                if (sum - num) - min(v[i],v[j]) > k {
                    ret ++;
                } else {
                    ret += 1;
                }
            }else {
                if (num - sum) - max(v[i],v[j]) > k {
                    ret ++;
                } else {
                    ret += 1;
                }
            }
        }
        i ++; 
        j --;
    }
    return ret;
}

void solve() {
    long long n;
    long long k;
    cin >> n >> k;
    long long i = 0;
    long long j = n - 1;

    vector<int> v;

    for(int i = 0; i < n; i ++) {
        long long curr; cin >> curr; v.push_back(curr);
    }

    set<long long> s;
    vector<long long> b;
    while (i < j) {
        long long sum = v[i] + v[j];
        if (s.count(sum) == 0) {
            b.push_back(sum);
        } else {
           s.insert(sum); 
        }
        i ++; 
        j --;
    }
    sort(b.begin(), b.end());

    int left = 0;
    int right = b.size();
    int maxCount = 0;
    while (left <= right) {
        int mid = (left + right + 1) / 2;
        long long l = check(mid - 1);
        long long m = check(mid);
        maxCount = max(maxCount, max(max(l,r), m));
        if (left < mid) {
            left = mid + 1;
        } else if (left > mid) {
            right = left - 1;
        }
    }
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
        solve();
    }
}
