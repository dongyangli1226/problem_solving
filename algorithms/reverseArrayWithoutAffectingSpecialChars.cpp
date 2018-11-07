//input a string that contains special character together with alphabets (‘a’ to ‘z’ and ‘A’ to ‘Z’)
//reverse the string, special characters should not be affected

#include <iostream>

bool isAlphabet(char c){
    return ( (c >='A' && c<='Z') || (c >='a' && c<='z'));
}

void reverse(std::string& s){
    int left = 0;
    int right = s.size()-1;

    while(left<right){
        if(!isAlphabet(s[left])){
            left++;
        }

        else if(!isAlphabet(s[right])){
            right--;
        }

        else{
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
}

int main(){
    std::string s = "a,bt,,,*)csb.;k";
    std::cout << "input: " << s << std::endl;
    reverse(s);
    std::cout << "output: " << s << std::endl;
}