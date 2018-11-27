//best time to buy and sell stocks
//similar to leetcode 53, Kadane's algorithm

#include <vector>

int maxProfit(std::vector<int>& prices) {
    int max_current = 0, max_profit = 0;

    for(int i=1; i<prices.size(); i++){
        max_current = std::max(0, max_current += (prices[i] - prices[i-1]));
        max_profit = std::max(max_profit, max_current);
    }

    return max_profit;
}


//normal understanding

int maxProfit2(std::vector<int> &prices) {
    int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = std::min(minPrice, prices[i]); //min price from day 0 to day i
        maxPro = std::max(maxPro, prices[i] - minPrice); //max profit from day 0 to day i
    }
    return maxPro;
}