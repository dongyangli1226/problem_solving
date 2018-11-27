//triangle
//Given a triangle
//find the minimum path sum from top to bottom. Each step you may move to **adjacent numbers** on the row below.
/*

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,0]
]

min path sum: 2-3-5-1
*/
#include <iostream>
#include <vector>

//bottom up
int minimumTotal(std::vector<std::vector<int>>& triangle) {
    std::vector<int> dp = triangle[triangle.size()-1];

    for(int i=triangle.size()-2; i>=0; i--){
        for(int j=0; j<triangle[i].size(); j++){
            dp[j] = triangle[i][j] + std::min(dp[j], dp[j+1]);
        }
    }

    return dp[0];
}