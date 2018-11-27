//geeksforgeeks
//Count ways to reach the nth stair using step 1, 2 or 3
//A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time.
//Implement a method to count how many possible ways the child can run up the stairs.

//similar to leetcode70

#include <iostream>

//recursive method
int findStep(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    else{// n is greater or equal to 3
        return findStep(n-3)+findStep(n-2)+findStep(n-1);
    }

}

//dp solution (optimized by dp)
int findStepDp(int n){
    int dp[n+1];

    //save the solution for n = 0,1,2
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
    }

    return dp[n];

}
