//array rotation

//similar to leetcode189, rotate by k steps

//Write a function that rotates a list by k elements.
//For example, [1, 2, 3, 4, 5, 6] rotated by two becomes [3, 4, 5, 6, 1, 2].
//Try solving this without creating a copy of the list.
//How many swap or move operations do you need?



#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    //Euclidean algorithm (explaination from GeeksforGeeks)
    //subtract smaller number from larger, GCD doesn’t change. 
    //divide smaller number, stops when we find remainder 0.

    if(b == 0){
        return a;
    }

    return gcd(b, a%b);
}

//juggling algorithm - using gcd (greatest common divisor)
void rotateListByK(vector<int>& nums, int k){
    int gcdOfSizeAndK = gcd(nums.size(), k);
    cout << "gcd: " << gcdOfSizeAndK << endl;
    int j,h;

    for(int i=0; i<gcdOfSizeAndK; i++){
        int temp = nums[i];
        j = i;

        while(true){
            h = k + j;
            if( h >= nums.size()){
                h = h-nums.size();
            }
            if( h == i){
                break;
            }
            nums[j] = nums[h];
            j = h;
        }

        nums[j] = temp;
    }
}

int main(){
    vector<int> nums{1,2,3,4,5,6};
    rotateListByK(nums, 2);

    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << ' ';
    }
    cout << endl;

}
