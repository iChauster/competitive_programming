#include "./config/bits/stdc++.h"
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int agg[55][35];
int dp[55][55*35];
int n, k, p, current, best;

int res(int idx, int plates){
    int ans = -1e9;
    if (idx > n || plates > p) {
        return ans;
    } else if (plates == p) {
        return 0;
    } else if (dp[idx][plates] != -1) {
        return dp[idx][plates];
    } else {
        for (int j = 0; j <= k; j ++){
            ans = max(ans, agg[idx][j] + res(idx + 1, j + plates));
        }
        dp[idx][plates] = ans;
        return ans;
    }
}


void _main(int TEST)
{
    cin >> n >> k >> p;
    memset(agg, 0, sizeof(agg));
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i ++) {
        for (int j = 1; j <= k; j ++){
            cin >> current;
            agg[i][j] = current + agg[i][j-1];
        }
    }

    int j = res(0,0);

    printf("%d\n", j);

}

int main()
{
    IOS;
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d: ", i);
        _main(i);
    }
    return 0;
}
