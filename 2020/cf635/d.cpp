//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;
int nr; int ng; int nb;
vector<long long> red;
vector<long long> green;
vector<long long> blue;

long long solution;
long long square(long long s) {
    return 1LL * s * s;
}
void subProblem(vector<long long> iterate, vector<long long> left, vector<long long> right) {
    for (auto i : iterate){
        auto l = lower_bound(left.begin(), left.end(), i);
        auto r = upper_bound(right.begin(), right.end(), i);
        if (l == left.end() || r == right.begin()) continue;
        r --;
        solution = min(solution, square(*l - i) + square(i - *r) + square(*r - *l));
    }
}

void solve() {
	cin >> nr >> ng >> nb;
    solution = LLONG_MAX;
    long long curr;
    red.clear();
    green.clear();
    blue.clear();
	for (int i = 0; i < nr; i ++) {
        cin >> curr;
        red.push_back(curr);
    }
    for (int i = 0; i < ng; i ++) {
        cin >> curr;
        green.push_back(curr);
    }
    for (int i = 0; i < nb; i ++){
        cin >> curr;
        blue.push_back(curr);
    }
    sort(red.begin(), red.end());
    sort(green.begin(), green.end());
    sort(blue.begin(), blue.end());
    subProblem(green, red, blue);
    subProblem(green, blue, red);
    subProblem(red, green, blue);
    subProblem(red, blue, green);
    subProblem(blue, red, green);
    subProblem(blue, green, red);

    printf("%lld\n", solution);
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
