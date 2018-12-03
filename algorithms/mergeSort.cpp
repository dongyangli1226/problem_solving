//useful for sorting linkedlist
//geeksforgeeks

#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int l, int m, int r){
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;

    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for(i=0; i<n1; i++){
        left[i] = arr[l+i];
    }

    for(j=0; j<n2; j++){
        right[j] = arr[m+1+j];
    }

    i=0; //initial index for first subarray
    j=0; //initial index for second subarray
    k=l; //initial index for merged subarray

    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    //copy remaining elements of left and right

    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> arr, int l, int r){
    if(l < r){
        int m = l+(r-1)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}