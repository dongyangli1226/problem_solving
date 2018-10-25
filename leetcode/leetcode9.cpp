//palindrome number
#include <string>

using namespace std;

bool isPalindrome(int x) {
    if(x<0){
        return false;
    }

    if(x==0){
        return true;
    }

    if(x%10 == 0){
        return false;
    }

/*
    int original_x=x;
    int rev=0;
    while(x){
        rev = rev*10 + x%10;
        x = x/10;
    }

    //return rev==original_x;
*/


    //faster:
    int rev=0;
    while(x > rev){
        rev = rev*10 + x%10;
        x = x/10;
    }

    return rev == x || rev/10 == x; //odd or even number of digits
}