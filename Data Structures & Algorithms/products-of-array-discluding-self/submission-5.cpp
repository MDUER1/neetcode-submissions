class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res (nums.size(), 1);

        // Store the prefix/left products
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[ i - 1] * nums[i - 1]; // Stores product of everything to the left of each index
        }

        // Multiply in all the right products
        int postfix{1};
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};