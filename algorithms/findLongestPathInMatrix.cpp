/*geeksforgeeks

Given a n*n matrix where all numbers are distinct
find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1.

We can move in 4 directions from a given cell (i, j)
i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cells have a difference of 1.

*/
#include <iostream>
#include <vector>

int findLongestFromCell(std::vector<std::vector<int> >& matrix, std::vector<std::vector<int> >& dp, int i, int j){
    if(i<0 || i>matrix.size()-1 || j<0 || j>matrix.size()-1){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(j < matrix.size()-1 && (matrix[i][j]+1 == matrix[i][j+1])){
        return dp[i][j] = 1 + findLongestFromCell(matrix, dp, i, j+1);
    }
    if(j > 0 && (matrix[i][j]+1 == matrix[i][j-1])){
        return dp[i][j] = 1 + findLongestFromCell(matrix, dp, i, j-1);
    }

    if(i < matrix.size()-1 && (matrix[i][j]+1 == matrix[i+1][j])){
        return dp[i][j] = 1 + findLongestFromCell(matrix, dp, i+1, j);
    }
    if(i > 0 && (matrix[i][j]+1 == matrix[i-1][j])){
        return dp[i][j] = 1 + findLongestFromCell(matrix, dp, i-1, j);
    }

    //if none of adjacent four cells is one greater
    return dp[i][j] = 1;
}

int findLongestPath(std::vector<std::vector<int> >& matrix){
    std::vector<std::vector<int> > dp(matrix.size(), std::vector<int>(matrix.size(), -1));
    int result = 1;

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix.size(); j++){
            if(dp[i][j] == -1){
                findLongestFromCell(matrix, dp, i, j);
            }

            result = std::max(result, dp[i][j]);
        }
    }

    return result;
}

int main() 
{ 
   std::vector<std::vector<int> > matrix = {{1, 2, 9}, 
                                            {5, 3, 8}, 
                                            {4, 6, 7}}; 
   std::cout << "Length of the longest path is " << findLongestPath(matrix) << std::endl; 
   return 0; 
} 