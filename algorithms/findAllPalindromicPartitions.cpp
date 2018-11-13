//input : string
//output all possible palindromic partitions of that string
//similar with leetcode 5

#include <iostream>
#include <vector>

std::vector<std::string> findAllPalindromicPartitions(std::string s){
    std::vector<std::string> result;

    int left, right, currentIndex = 0;
    int currentLength;

    while(currentIndex < s.size()){
        left = currentIndex;
        right = currentIndex;

        while(right < s.size()-1 && s[right] == s[right+1]){
            right++;
        }

        currentIndex = right + 1;

        while(right < s.size()-1 && left > 0 && s[left-1] == s[right+1]){
            currentLength = right - left + 1;
            std::string newPalindromicStr = s.substr(left, currentLength);
            result.push_back(newPalindromicStr);
            right++;
            left--;
        }

        currentLength = right - left + 1;
        std::string newPalindromicStr = s.substr(left, currentLength);
        result.push_back(newPalindromicStr);
   }

   return result;
}

int main(){
    std::string s = "nitin";
    std::vector<std::string> res;
    res = findAllPalindromicPartitions(s);
    for(int i=0; i<res.size(); i++){
        std::cout << res[i] << std::endl;
    }
}