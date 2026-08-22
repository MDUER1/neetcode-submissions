class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
         std::vector<int> ans( nums.size() * 2);
         int n{static_cast<int>(nums.size())};

         for (int i{}; i < nums.size(); ++i)
         {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
         }

         return ans;
    }
};