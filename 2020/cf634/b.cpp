//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

char answer[2001];
char sub[2001];
int n;
int a;
int b;
void solve() {
	cin >> n >> a >> b;
    // write the first sequence based on b
    for (char i = 'a'; i < b + 'a'; i ++) {
        sub[i - 'a'] = i;
    }
    // extend it until a
    for (int i = b; i < a; i ++) {
        char prev = sub[i - 1];
        sub[i] = prev;
    }
    

    int left = 0;
    // oscillate until n
    while (left < n) {
        for (int i = 0; i < min(a, n - left); i ++) {
            answer[left + i] = sub[i]; 
        }
        left += a;
    }

    for (int i = 0; i < n; i ++) {
        printf("%c", answer[i]);
    }
    printf("\n");
    memset(answer, 0, sizeof(answer));
    memset(sub, 0, sizeof(sub));

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
