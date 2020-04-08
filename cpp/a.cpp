#include "./config/bits/stdc++.h"

using namespace std;

int houses, budget;
int houseCost, sol;
void _main(int TEST)
{
    sol = 0;

    cin >> houses >> budget;

    vector<int> v;

    for (int i = 0; i < houses; i ++){
        cin >> houseCost;
        v.push_back(houseCost);
    }

    sort(v.begin(), v.end(), greater<int>());

    while(budget > 0 && !v.empty()) {
        budget -= v.back();
        v.pop_back();

        sol = (budget >= 0) ? sol + 1 : sol;
    }

    printf("%d\n", sol);
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
