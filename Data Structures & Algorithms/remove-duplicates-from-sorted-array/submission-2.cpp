class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k{ 1 };

        for (std::size_t i{1}; i < nums.size(); ++i)
        {
            if (nums[i] != nums[k - 1])
            {
                nums[k] = nums[i];
                ++k;
            }
        }

        return k;
    }
};