//count number of 1s in binary representation of an intege

#include <iostream>


//theta(logn) O(logn)
int countSetBits(int n){

    int result = 0;
    while(n){
        result += n & 1;
        n >>= 1;
    }

    return result;
}

//recursive
int countSetBits(int n){

    if(n == 0){
        return 0;
    }

    return (n&1) + countSetBits(n>>1);
}

//Brian Kernighan’s Algorithm (below From geeksforgeeks)
//loop through only number of set bits time, unlike the first approach go through every bits
//Subtraction of 1 from a number toggles all the bits (from right to left) till the rightmost set bit(including the rightmost set bit).
//So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the rightmost set bit.
//If we do n & (n-1) in a loop and count the no of times loop executes we get the set bit count.
//The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer.
//O(logn)

int countSetBits(int n){
    int count = 0;

    while(n){
        n &= (n-1);
        count++;
    }

    return count;
} // this can also be written in recursive way