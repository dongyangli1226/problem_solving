//Longest Palindromic Substring
//(substring that whether you read from the front or the back)
// xxaxx, xxaaxx (odd pal and even pal)

#include <iostream>

using namespace std;

string longestPalindrome(string s) {
    if (s.empty()){
        return "";
    }
    if (s.size() == 1){
        return s;
    }

    int longest_length = 1;
    int longest_start = 0;
    int current_index = 0;

    while(current_index < s.size()){
        if(s.size()-current_index <= longest_length/2){
            break;
        }
        int left = current_index, right = current_index;

        while (right < s.size() - 1 && s[right] == s[right+1]){
            right++;
        }

        current_index = right + 1;

        while (right < s.size() -1 && left > 0 && right < s.size() && s[left-1] == s[right+1]){
            left--;
            right++;
        }

        int new_length = right - left + 1;
        if(new_length > longest_length){
            longest_length = new_length;
            longest_start = left;
        }
    }

    return s.substr(longest_start, longest_length);

}

int main(){
    string s = "abccbw";
    cout << longestPalindrome(s) << endl;
}