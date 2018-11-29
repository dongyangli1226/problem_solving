//rotate array to the right by k elements
//similar to rotateListByK(juggling algo)

#include <vector>

int gcd(int a, int b){
    //Euclidean algorithm (explaination from GeeksforGeeks)
    //subtract smaller number from larger, GCD doesn’t change. 
    //divide smaller number, stops when we find remainder 0.

    if(b == 0){
        return a;
    }

    return gcd(b, a%b);
}

void rotate(std::vector<int>& nums, int k) {
    k = k%nums.size(); // k could be greater than size
    int gcdOfSizeAndK = gcd(nums.size(), nums.size()-k);
    int j,h;

    for(int i=0; i<gcdOfSizeAndK; i++){
        int temp = nums[i];
        j = i;

        while(true){
            h = nums.size()-k + j;
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