//maximal square
//given 2D binary matrix filled with 0's and 1's
//find largest square containing only 1's and return its area

#include <vector>

//DP idea is to form possible square at point (i, j) as dp[i][j]
//form square from bottom right
//obviously, top row and leftmost column dp[i][j] = matirx[i][j]

int maximalSquare(std::vector<std::vector<char> >& matrix){
    if(matrix.size() == 0){
        return 0;
    }

    int maxWidth=0;
    std::vector<std::vector<int> > dp(matrix.size(), std::vector<int>(matrix[0].size(), 0));

    for(int i=0; i<matrix[0].size(); i++){
        dp[0][i] = matrix[0][i] - '0';
        maxWidth = std::max(maxWidth, dp[0][i]);
    }

    for(int i=0; i<matrix.size(); i++){
        dp[i][0] = matrix[i][0] - '0';
        maxWidth = std::max(maxWidth, dp[i][0]);
    }

    for(int i=1; i<matrix.size(); i++){
        for(int j=1; j<matrix[0].size(); j++){
            if(matrix[i][j] == '1'){
                dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1])) + 1;
                maxWidth = std::max(maxWidth, dp[i][j]);
            }
        }
    }

    return maxWidth * maxWidth;
}