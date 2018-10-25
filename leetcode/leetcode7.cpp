//reverse integer

#include <iostream>

using namespace std;

int reverse(int x){
    bool isNegative = false;
    if(x < 0){
        isNegative = true;
        x = 0 - x;
    }

    int reverseInt = 0, previousInt = 0;
    while(x){
        reverseInt = reverseInt * 10 + x%10;
        
        //check overflow
        //check if previous_int = (reverseInt-x%10)/10
        if(previousInt != (reverseInt-x%10)/10){
            return 0;
        }
        previousInt = reverseInt;
        x = x/10;
    }
    
    return isNegative?(0-reverseInt):reverseInt;
}