//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;
int result[51][51];
void solve() {
	int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (n * a != m * b) {
	  printf("NO\n");
      return;
    }

    int shift = 0;

    for (shift = 1; shift < m; shift++) {
      if (shift * n % m == 0) {
        break;
      }
    }

    for (int i = 0, dx = 0; i < n; i++, dx += shift) {
      for (int j = 0; j < a; j++) {
        result[i][(j + dx) % m] = 1;
      }
    }

    printf("YES\n");

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d", result[i][j]);
      }

      printf("\n");
    }
}
	
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
		memset(result, 0, sizeof(result));
    	solve();
    }
}
