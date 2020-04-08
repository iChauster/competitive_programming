#include "./config/bits/stdc++.h"

using namespace std;

int agg[55][35];
int dp[55][55*35];
int n, k, p, current, best;
void _main(int TEST)
{
    cin >> n >> k >> p;
    memset(agg, 0, sizeof(agg));
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i ++) {
        agg[i][0] = 0;
        for (int j = 1; j < k + 1; j ++){
            cin >> current;
            agg[i][j] = current + agg[i][j-1];
        }
    }

    best = 0;
    for (int i = 0; i < n; i ++){
        for (int plates = 0; plates <= p; plates ++){
            dp[i][p] = 0;
            if (i == 0){
                dp[i][plates] = agg[0][plates];
            } else {
                for (int z = 0; z <= min(plates, k); z ++) {
                    dp[i][plates] = max(dp[i][plates], agg[i][z] + dp[i - 1][plates - z]);
                }
            }
            best = max(best, dp[i][p]);
        }
    }

    printf("%d\n", best);

}

int main()
{
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d: ", i);
        _main(i);
    }
    return 0;
}
