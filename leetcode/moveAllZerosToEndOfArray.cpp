/**
Description: the input is an int array (vector in c++), what we need to do is to move all zeros to the end of array without changing the order of the non-zero ones.

example: input {0, 1, 3, 4, 2, 0, 1}
		 output {1, 3, 4, 2, 1, 0, 0}

*/

#include <iostream>
#include <vector>
std::vector<int> moveZeros(std::vector<int> & nums){
	int p = 0, q = 0; //index for iterating array and manipulating the array

	//move all non-zeros to the front of the array (overwrite)
	while(q < nums.size()){
		if(nums[q] != 0){
			nums[p] = nums[q];
			p++;
		}
		q++;
	}

	while(p < nums.size()){
		nums[p] = 0;
		p++;
	}

	return nums;

}

//test output
int main(){

	std::vector<int> input;  //{1,0,4,3,0,0,2}
	input.push_back(1);
	input.push_back(0);
	input.push_back(4);
	input.push_back(3);
	input.push_back(0);
	input.push_back(0);
	input.push_back(2);

	std::vector<int> input1;  //{0,0,4,3,0,0,0}
	input1.push_back(0);
	input1.push_back(0);
	input1.push_back(4);
	input1.push_back(3);
	input1.push_back(0);
	input1.push_back(0);
	input1.push_back(0);

	std::vector<int> input2;  //{1,1,4,3,2,6,9}
	input2.push_back(1);
	input2.push_back(1);
	input2.push_back(4);
	input2.push_back(3);
	input2.push_back(2);
	input2.push_back(6);
	input2.push_back(9);

	std::vector<int> input3;  //{0,0,0,0,0,0,0}
	input3.push_back(0);
	input3.push_back(0);
	input3.push_back(0);
	input3.push_back(0);
	input3.push_back(0);
	input3.push_back(0);
	input3.push_back(0);

	moveZeros(input);
	moveZeros(input1);
	moveZeros(input2);
	moveZeros(input3);

	for(int i=0; i < input.size(); i++){
		std::cout << input[i] << " ";
	}

	std::cout << std::endl;

	for(int i=0; i < input1.size(); i++){
		std::cout << input1[i] << " ";
	}

	std::cout << std::endl;

	for(int i=0; i < input2.size(); i++){
		std::cout << input2[i] << " ";
	}

	std::cout << std::endl;

	for(int i=0; i < input3.size(); i++){
		std::cout << input3[i] << " ";
	}

	std::cout << std::endl;

	return 0;
}