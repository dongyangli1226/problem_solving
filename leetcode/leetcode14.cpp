//longest common prefix

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string res = "";
    char c;

    //return empty string if no string in strs
    if(strs.size() == 0) return res;

    //loop into the chars of first string in strs
    for(int i=0; i<strs[0].size(); i++){
        c = strs[0][i];

        //compare char c to chars of other strings in strs at same index
        for(auto s:strs){
            if(strs.size() < i || s[i] != c){
                return res;
            }
        }
        //if all other strings have char c at the same index then add c to result
        res.push_back(c);
    }

    return res;
}