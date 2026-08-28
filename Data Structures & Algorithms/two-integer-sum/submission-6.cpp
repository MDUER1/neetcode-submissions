class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> complement;
        std::vector<int> res;

        for (int i{}; i < nums.size(); ++i) {
            for (int j{i + 1}; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};













