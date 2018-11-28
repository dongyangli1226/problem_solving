//set matrix zeroes
//if matrix[i][j] == 0, then the row and column it is at will all turned to zero
//try to use O(n) space

#include <vector>

void setZeros(std::vector<std::vector<int> >& matrix){

    int m = matrix.size(), n = matrix[0].size();
    bool firstRowZero=false, firstColZero=false; //edge case: the first item. (matrix[0][0])

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 0){
                if(i==0){
                    firstRowZero = true;
                }
                if(j==0){
                    firstColZero = true;
                }
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(firstRowZero){
        for(int i=0; i<n; i++){
            matrix[0][i] = 0;
        }
    }
    if(firstColZero){
        for(int i=0; i<m; i++){
            matrix[i][0] = 0;
        }
    }

}

int main(){
    std::vector<std::vector<int> > matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeros(matrix);

    return 0;
}