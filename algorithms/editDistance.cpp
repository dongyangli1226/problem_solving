//geeksforgeeks
//Given two strings str1 and str2 and below operations that can performed on str1.
//Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

#include <iostream>
#include <vector>

int editDistance(std::string s1, std::string s2){
    std::vector<std::vector<int> > dp(s1.size()+1, std::vector<int>(s2.size()+1));

    for(int i=0; i<=s1.size(); i++){

        for(int j=0; j<=s2.size(); j++){

            if(i == 0){ //if s1 is empty, then need to insert all s2 chars
                dp[i][j] = j;
            }
            else if(j == 0){ // if s2 is empty, then need to remove all s1 chars
                dp[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + std::min(dp[i-1][j], std::min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }

    return dp[s1.size()][s2.size()];
}

int main() 
{ 
    std::string str1 = "sunday"; 
    std::string str2 = "saturday"; 
  
    std::cout << editDistance(str1, str2) << std::endl; 
  
    return 0; 
} 