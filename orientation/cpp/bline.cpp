//#include <bits/stdc++.h>
#include "./config/bits/stdc++.h"

using namespace std;
int n;
long long timelimit;
vector<long long> negativeList;
vector<long long> positiveList;
long long curr;

long long binarySearch(long long key, long long left, long long right, vector<long long> l) {
    // preserve the values that work (keep left)
    if (right < left) {
        return -1;
    }

    long long mid = (left + right) / 2;
    long long target = timelimit - key;
    long long value = l[mid];

    if (value > target) {
        return binarySearch(key, left, mid - 1, l);
    } else if (value < target) {
        long long nextWorking = binarySearch(key, mid + 1, right, l);
        
        if (nextWorking != -1) {
            return nextWorking;
        } else {
            return mid;
        }
    } else {
        // if exact match, we can't get any better
        return mid;
    }

}

void solve() {
    cin >> n >> timelimit;
    for (int i = 0; i < n; i ++) {
        cin >> curr;
        if (curr < 0) {
            negativeList.push_back(curr * -1);
        } else {
            positiveList.push_back(curr);
        }
    }

    reverse(negativeList.begin(), negativeList.end());

    long long maxBonuses = 0;
    for (long long i = positiveList.size() - 1; i >= 0; i --){
        long long farB = positiveList[i];
        if (farB <= timelimit){
            maxBonuses = max(maxBonuses, i + 1);
        }
        // turn around values
        if (farB * 2 > timelimit) {
            continue;
        } else if (farB * 2 > timelimit) {
            maxBonuses = max(maxBonuses, farB * 2);
        } else {
            long long value = binarySearch(2 * farB, 0, negativeList.size() - 1, negativeList);
            if (value >= 0) {
                maxBonuses = max(maxBonuses, i + value + 2);
            } 
        }
    }

    for (long long i = negativeList.size() - 1; i >= 0; i --){
        long long farB = negativeList[i];
        if (farB <= timelimit){
            maxBonuses = max(maxBonuses, i + 1);
        }
        if (farB * 2 > timelimit) {
            continue;
        } else if (farB * 2 > timelimit) {
            maxBonuses = max(maxBonuses, farB * 2);
        } else {
            long long value = binarySearch(2 * farB, 0, positiveList.size() - 1, positiveList);
            if (value >= 0){
                maxBonuses = max(maxBonuses, i + value + 2);
            }
        }
    }

    printf("%lld\n", maxBonuses);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
