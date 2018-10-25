//zigzag conversion

//move each char to a different row
//direction, up or down

#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows){
    vector<string> zzStr(numRows);
    int row = 0; 
    int index = 0;
    int down = 1;
    
    if(s.empty()){
        return "";
    }
    if(numRows == 1){
        return s;
    }

    while(index < s.size()){
        zzStr[row] += s[index];
        if(down == 1){
            row++;
        }
        if(down == 0){
            row--;
        }
        index++;
        if(row >= numRows){
            row = numRows-2;
            down = 0;
        }
        if(row < 0){
            row = 1;
            down = 1;
        }
    }

    string zig = "";
    for(int i=0; i<zzStr.size(); i++){
        zig += zzStr[i];
    }

    return zig;
}

int main(){
    string s = "ABCDEFGH";
    cout << "zigzag: " << convert(s, 2) << endl;
}