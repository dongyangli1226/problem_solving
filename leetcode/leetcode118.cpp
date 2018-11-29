//Pascal's Triangle

/*

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int> > dp;
    if(numRows == 0){
        return dp;
    }
    
    std::vector<int> first(1,1);
    dp.push_back(first);
    
    if(numRows > 1){
        std::vector<int> second(2,1);
        dp.push_back(second);
    }
    
    for(int i=2; i<numRows; i++){

        std::vector<int> ithRow(i+1,1);
        for(int j=1; j<ithRow.size()-1; j++){
            ithRow[j] = dp[i-1][j-1]+dp[i-1][j];
        }
        dp.push_back(ithRow);

    }
    
    return dp;
}