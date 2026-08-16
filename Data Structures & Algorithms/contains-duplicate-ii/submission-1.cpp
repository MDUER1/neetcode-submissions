class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_set<int> window;

        for (std::size_t i{0}; i < nums.size(); ++i)
        {
            if (window.contains(nums[i]))
            {
                return true;
            }

            window.insert(nums[i]);

            if (window.size() > static_cast<std::size_t>(k))
            {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};