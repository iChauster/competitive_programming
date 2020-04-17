#include <bits/stdc++.h>
//#include "./config/bits/stdc++.h"

using namespace std;
int n;
long long timelimit;
vector<long long> negativeList;
vector<long long> positiveList;
long long curr;
long long maxBonuses;

void subp(vector<long long> l, vector<long long> b) {
    for (long long i = 0; i < l.size(); i ++) {
        long long element = l[i];
        if (element <= timelimit) {
            maxBonuses = max(maxBonuses, i + 1);
        }
        if (2 * element > timelimit) {
            continue;
        } else {
            if (b.size() > 0){
                long long extraTime = timelimit - 2 * element;
                auto ub = lower_bound(b.begin(), b.end(), extraTime);
                if (*ub != extraTime)
                    ub --;
                long long index = ub - b.begin();
                maxBonuses = max(maxBonuses, i + index + 2);
            }
        }

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

    maxBonuses = 0;

    subp(positiveList, negativeList);
    subp(negativeList, positiveList);
    
    printf("%lld\n", maxBonuses);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
