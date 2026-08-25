class Solution {
public:
int partition(vector<int>& nums, int left, int right) {
    //int mid = (left + right) >> 1; // Find middle element with bitshift
    //swap(nums[mid], nums[left + 1]); // Move the privot to left + 1

    // Median of three pivot selection - swaps the values not the indicies
    // Now we center left + 1, through three checks, which is our pivot
    if (nums[left] > nums[right])
        swap(nums[left], nums[right]);
    if (nums[left + 1] > nums[right])
        swap(nums[left + 1], nums[right]);
    if (nums[left] > nums[left + 1])
        swap(nums[left], nums[left + 1]);
    
    int pivot = nums[left + 1]; // store the pivot
    // Two pointers, int i searches from left to right, and j searches from right to left
    int i = left + 1;
    int j = right;

// Searches for incorrect values on either sides of the pivot, and swithces them
    while (true) {
        while (nums[++i] < pivot);
        while (nums[--j] > pivot);
        if (i > j) break;
        swap(nums[i], nums[j]);
    }

// Now we place the pivot at index j
    nums[left + 1] = nums[j];
    nums[j] = pivot;
    return j;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (right <= left + 1) { //section contains at least two elements, for one nothing needs to be done
        if (right == left + 1 && nums[right] < nums[left]) // Fx checks if two elements and does fx 83 to 38
            swap(nums[left], nums[right]);
        return; // stops the recursive call 
    }

    int j = partition(nums, left, right); //Rearranged into values < pivot |pivot | values > pivot and return pivotinde
    quickSort(nums, left, j - 1); // Sort the left half
    quickSort(nums, j + 1, right); // Sort the right half
} // Skipping j since the pivot is already sorted


    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1); // Quick sort works on the entire vector
        return nums;
    }
};