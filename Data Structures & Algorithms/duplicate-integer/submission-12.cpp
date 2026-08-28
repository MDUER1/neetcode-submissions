class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for (int i{}; i < nums.size(); i++) {
            if (seen.contains(nums[i])) {
                return true;
            } else {
                seen.insert(nums[i]);
            }
        }
        return false;
    }
};