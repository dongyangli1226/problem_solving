//Kth Largest element in an array

//max heap - priority queue, min heap - multiset
#include <vector>
#include <queue>

int findKthLargest(std::vector<int>& nums, int k){

    std::priority_queue<int> pq(nums.begin(), nums.end());
    for(int i=0; i<k-1; i++){
        pq.pop();
    }

    return pq.top();
}

//build max heap. see algorithm/