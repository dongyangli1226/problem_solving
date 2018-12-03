//geeksforgeeks
//top-down
#include <vector>

void heapify(std::vector<int>& arr, int n, int i){
    int largest = i; //initialize largest as root
    int left = 2*i+1;
    int right = 2*i+2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr){
    for(int i=arr.size()/2-1; i>=0; i--){
        heapify(arr, arr.size()-1, i);
    }

    for(int i=arr.size()-1; i>=0; i--){
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}