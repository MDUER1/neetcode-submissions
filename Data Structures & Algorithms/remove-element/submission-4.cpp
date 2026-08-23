class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k{};

        for ( int num : nums) {
            if (num == val) {
                std::erase(nums, num);
            }
        }

        return k = nums.size();
    }
};