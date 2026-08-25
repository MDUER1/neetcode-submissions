class Solution {
public: 
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
}

private:
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r); // Assumes that 1..m and m+1..r is sorted
    }

    void merge(vector<int>& arr, int l, int m, int r) {
        vector<int> temp;
        int i{l}; // i starts at the first index of the left sorted half
        int j{m + 1}; // j starts at the first index of the right sorted half

        while (i <= m && j <= r) { // Compare elements while both halves still have elements left
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]); // Add the smallest element in left side and increment to next
            } else {
                temp.push_back(arr[j++]); // Repeat for right side
            }
        }

        // Appends the last element
        while (i <= m) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);

        // Copies the sorted result back into arr
        for (int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
    }

};










































