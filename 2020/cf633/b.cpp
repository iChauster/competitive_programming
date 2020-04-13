//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

long long sortArray[100001];
int n;

void solve() {
	int length;
	cin >> n;
	memset(sortArray, 0, sizeof(sortArray));

    for (int i = 0; i < n; i ++){
        cin >> sortArray[i];
    }

    sort(sortArray, sortArray + n);

    int j = n - 1;
    int i = 0;
    vector<long long> ans;

    while (i <= j) {
        if (i < j) {
            ans.push_back(sortArray[i]);
        } 
        ans.push_back(sortArray[j]);
        i ++;
        j --;
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i ++){
        if (i) printf(" ");
        printf("%lld", ans[i]);
    }
    printf("\n");
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
