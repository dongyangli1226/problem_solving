//combination Sum III
//use k numbers that add up to n (only use 1-9)
//each combination should be a unique set of numbers (no duplicate)

#include <vector>

std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> result;
    std::vector<int> combination;
    calculateCombination(n, k, result, combination);
    return result;
}

void calculateCombination(int n, int k, std::vector<std::vector<int>>& result, std::vector<int>& combination){
    if(n == 0 && combination.size()==k){
        result.push_back(combination);
        return;
    }
    
    if(combination.size() < k){
        for(int i= combination.empty()? 1 : combination.back()+1; i<10; i++){
            combination.push_back(i);
            calculateCombination(n-i, k, result, combination);
            combination.pop_back();
        }
    }

}