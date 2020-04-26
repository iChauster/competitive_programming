//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
    cin >> n >> k;
    vector<int> csizes(n);
    vector<float> limits(k);
    for (int i = 0; i < n; i ++) {
        cin >> csizes[i];
    }
    sort(csizes.begin(), csizes.end());

    for (int i = 0; i < k; i ++){
        cin >> limits[i];
    }
    long long blimit = 0;
    long long j = csizes.size() - 1;
    long long count = 0;
    for (int i = k; i > 0; i --) {
        if (j < 0)
            break;
        while(csizes[j] >= i) {
            j --;
            count ++;
            if (j == -1)
                break;
        }
        blimit = max(blimit, (long long) ceil(count/limits[i - 1]));
    }
    count = 0;
    printf("%lld\n", blimit);
    while(count < blimit) {
        long long right = csizes.size() - count - 1;
        long long it = ceil((1.0*right + 1)/blimit);
        printf("%lld ", it);
        for (int i = 0; i < it; i ++) {
            if (i)
                printf(" %d", csizes[right - i * blimit]);
            else
                printf("%d", csizes[right - i * blimit]);
        }
        printf("\n");
        count ++;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
