#include "./config/bits/stdc++.h"

using namespace std;

int n, k;

int isValid(vector<int> v, int proj) {
    int sum = 0;
    for (int i = 0; i < v.size(); i ++){
        sum += ceil((double)v[i]/proj) - 1;
        if (sum > k) {
            return 1;
        }
    }
    if (sum <= k) {
        return 0;
    }
}
int binSearch(int left, int right, vector<int> v) {
    while(left < right){
       int mid = (right + left) / 2;
        if (isValid(v, mid) == 1){
            left = max(mid + 1, left + 1);
        } else {
            right = mid;
        } 
    }
    
    return right;

}

void _main(int TEST)
{
    cin >> n >> k;

    vector<int> v;
    vector<int> iv;
    int curr = 0;
    int maxdiff = 0;

    for (int i = 0; i < n; i ++){
        cin >> curr;
        iv.emplace_back(curr);
    }

    for (int i = 1; i < n; i ++) {
        int diff = iv[i] - iv[i-1];
        maxdiff = max(maxdiff, diff);
        v.emplace_back(diff);
    }

    int res = binSearch(1, maxdiff, v);
    printf("%d\n", res);

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
