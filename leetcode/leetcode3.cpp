//related topics need to review
//longest common subsequence (DP)
//longest common substring (suffix trie)

//this one is longest substring without repeating characters

//1. check if dict contains current char, if exist, then update pointer
//2. calculate max
//3. update dict

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int pointer = 0, index = 0;
    unordered_map<char, int> map;
    int maximum = 0;

    while(index < s.size()){
        if(map.find(s[index]) != map.end()){
            pointer = max(pointer, map[s[index]]+1);
        }
        maximum = max(maximum, index-pointer+1);
        map[s[index]] = index;
        index++;
    }

    return maximum;
}

int main(){
    string s = "pwwkew";
    cout << " longest length of substring without repeating char: ";
    cout << lengthOfLongestSubstring(s) << endl;
}