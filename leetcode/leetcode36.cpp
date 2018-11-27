//valid sudok

#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char> >& board){

    for(int i=0; i<board.size(); i++){
        std::unordered_set<char> row;
        std::unordered_set<char> col;
        std::unordered_set<char> cube;

        for(int j=0; j<board[0].size(); j++){
            
            //insertion of hashset returns a pair of iterator and a boolean value
            if(board[i][j] != '.' && !row.insert(board[i][j]).second){
                return false;
            }

            if(board[j][i] != '.' && !col.insert(board[j][i]).second){
                return false;
            }

            int rowIndex = 3 * (i/3) + j/3;
            int colIndex = 3 * (i%3) + j%3;

            if(board[rowIndex][colIndex] != '.' && !cube.insert(board[rowIndex][colIndex]).second){
                return false;
            }
        }
    }

    return true;
}


//optimized solution
//mark flags to show whether a number has appeared in row, col and cube
bool isValidSudoku(std::vector<std::vector<char> >& board){

    int row[9][9] = {0};
    int col[9][9] = {0};
    int cube[9][9] = {0};
    int numIndex;
    int cubeIndex;

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j] != '.'){
                numIndex = board[i][j] - '0' - 1;
                cubeIndex = 3*(i/3) + j/3;
                if(row[i][numIndex] || col[j][numIndex] || cube[cubeIndex][numIndex]){
                    return false;
                }

                row[i][numIndex] = 1;
                col[j][numIndex] = 1;
                cube[cubeIndex][numIndex] = 1;
            }
        }
    }
    return true;
}