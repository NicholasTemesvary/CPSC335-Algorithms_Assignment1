#include "sorting_algorithms.h"

/*
insertion_sort function sorts the array in-place
@Parameters:
    nums: a reference to the vector of integers to be sorted
@Returns:
    void.
    the algorithm sorts the vector in-place. so, it does not return anything. 
*/
void insertion_sort(vector<int>& nums){
    // TODO 
    int n = nums.size();
    
    for (int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i - 1;
        
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        
        nums[j + 1] = key;
    }
}
