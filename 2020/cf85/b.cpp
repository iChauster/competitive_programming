//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


int n;
long long wealth;
int people[100001];
void solve() {
	cin >> n >> wealth;
    for (int i = 0; i < n; i ++) {
        cin >> people[i];
    }
    sort(people, people + n);

    int div = 0;
    int w = 0;
    long long sum = 0;
    for (int j = n - 1; j >= 0; j --) {
        sum += people[j];
        div ++;
        if ((sum / div) < wealth) {
            break;
        } else {
            w ++;
        }
    }
    printf("%d\n", w);
    memset(people, 0, sizeof(people));

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
