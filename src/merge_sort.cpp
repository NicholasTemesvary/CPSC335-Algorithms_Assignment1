#include "sorting_algorithms.h"

vector<int> aux;
/*  
merge function will merge two sorted sub-arrays, 
one starts from `low` and goes until `mid`
second starts from `mid+1` and goes until `high`
e.g.
    1   4 6  8     3 5 7
    ^        ^         ^
    low      mid       high

@Parameters:
    nums: a reference to the vector of numbers
    low: start point of first sub-array
    mid: end of left-sub-array
    high: end of right-sub-array

@Returns:
    the function does NOT return anything
    it merges the sub-arrays in-place.
*/
void merge(vector<int>& nums, int low, int mid, int high){
    // TODO
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    std::vector<int> left(n1);
    std::vector<int> right(n2);

    // Copy data to temp arrays left[] and right[]
    for (i = 0; i < n1; i++)
        left[i] = nums[low + i];
    for (j = 0; j < n2; j++)
        right[j] = nums[mid + 1 + j];

    // Merge the temp arrays back into nums[low..high]
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            nums[k] = left[i];
            i++;
        } else {
            nums[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if any
    while (i < n1) {
        nums[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if any
    while (j < n2) {
        nums[k] = right[j];
        j++;
        k++;
    }
   
}

/*
merge_sort function will sort the array in-place in the given bounds
@Parameters:
    nums: a reference to the vector of integers to be sorted
    low: start index of the array to be sorted
    high: end index of the array to be sorted
@Returns:
    void. 
    the algorithm sorts the vector in-place. so, it does not return anything.
*/
void _merge_sort(vector<int>& nums, int low, int high){
    // TODO
    // check if the bounds are correct
   if (low >= high) return;
   if (low < high) {
        // Find the middle point
        int mid = low + (high - low) / 2;

        // Sort first and second halves
        _merge_sort(nums, low, mid);
        _merge_sort(nums, mid + 1, high);

        // Merge the sorted halves
        merge(nums, low, mid, high);
    }
}

/*
merge_sort function sorts the array in-place
@Parameters:
    nums: a reference to the vector of integers to be sorted
@Returns:
    void.
    the algorithm sorts the vector in-place. so, it does not return anything. 
*/
void merge_sort(vector<int>& nums){
    aux.resize(nums.size(), 0);
    _merge_sort(nums, 0, nums.size()-1);
}
