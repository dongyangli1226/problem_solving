//pascal's Triangle II
//Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

#include <vector>

std::vector<int> getRow(int rowIndex) {
    std::vector<int> resultRow(rowIndex+1, 0);
    resultRow[0] = 1;

    for(int i=1; i<rowIndex+1; i++){
        for(int j=rowIndex; j>=1; j--){
            //calculate from the back
            resultRow[j] += resultRow[j-1];
        }
    }
    return resultRow;
}