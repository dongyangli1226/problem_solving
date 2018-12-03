//geeksforgeeks

#include <vector>


/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */

int partition(std::vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = (low - 1); // index of smaller element

    for(int j=low; j<=high-1; j++){
        if(arr[j] <= pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(std::vector<int>& arr, int low, int high){
    if(low < high){
        int partitionIndex = partition(arr, low, high);

        quickSort(arr, low, partitionIndex-1);
        quickSort(arr, partitionIndex+1, high);
    }
}

