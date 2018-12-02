//dynamic programming

/* geeksforgeeks
Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
*/
#include <iostream>
#include <vector>

int lcsLength(std::string s1, std::string s2){
    std::vector<std::vector<char> > dp(s1.size(), std::vector<char>(s2.size()));

    for(int i=0; i<s1.size(); i++){

        for(int j=0; j<s2.size(); j++){

            if(i == 0 || j == 0){
                dp[i][j] = 1;
            }

            else if(s1[i-1] == s2[j-1]){ //if last char matches
                dp[i][j] = dp[i-1][j-1] + 1;
            }

            else{
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    //L[i][j] contains length of LCS for X[0..i] and Y[0..j]
    return dp[s1.size()-1][s2.size()-1];
}

int main(){
    std::string s1 = "AGGTAB";
    std::string s2 = "GXTXAYB";

    std::cout << lcsLength(s1, s2) << std::endl;
    return 0;
}