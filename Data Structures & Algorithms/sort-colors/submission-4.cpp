class Solution {
public:
    void sortColors(vector<int>& nums) {
        for (int i{}; i < nums.size(); ++i) {
            int j = i + 1;

            if (!(j < nums.size())) {
                j = nums.size() - 1;
            }

            if (nums[i] > nums[j]) {
                std::swap(nums[i], nums[j]);
                i = -1;
                j = 0;
            }
        }

    }
};