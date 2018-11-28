//ugly number II
//ugly numbers are positive numbers whose prime factors only include 2, 3, 5

#include <vector>

int nthUglyNUmber(int n){
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return 1;
    }

    int p2 = 0, p3 = 0, p5 = 0;
    std::vector<int> dp(n, 0);

    dp[0] = 1;
    for(int i=1; i<n; i++){
        dp[i] = std::min(dp[p2] * 2, std::min(dp[p3] * 3, dp[p5] * 5));
        //can't use else if and else, since when dp[i] = 6 we need to move both p2 and p3
        if(dp[i] == dp[p2] * 2){
            p2++;
        }
        if(dp[i] == dp[p3] * 3){
            p3++;
        }
        if(dp[i] == dp[p5] * 5){
            p5++;
        }
    }

    return dp[n-1];
}