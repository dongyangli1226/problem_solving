//word break
//Given a non-empty string s and a dictionary wordDict containing a list of non-empty words
//determine if s can be segmented into a space-separated sequence of one or more dictionary words.

//Input: s = "leetcode", wordDict = ["leet", "code"]
//Output: true
//Explanation: Return true because "leetcode" can be segmented as "leet code".

#include <iostream>
#include <vector>
#include <algorithm>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    if(wordDict.size() == 0){
        return false;
    }
    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for(int i=1; i<=s.size(); i++){
        for(int j=0; j<i; j++){
            //dp[j]==true means 0 to j substr exist in dict
            // then we check if j to i substr exist in dict
            // if so, then we update dp[i] is true since 0 to j and j to i substr both exist in dict
            if(dp[j] && std::find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()){
                dp[i] = true;
                break;
            }
        }
    }

    return dp[s.size()];
}

int main(){
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet", "code"};

    std::cout << wordBreak(s, wordDict) << std::endl;
    return 0;
}