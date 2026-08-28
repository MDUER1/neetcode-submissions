class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
          vector<int> ans(static_cast<int>(nums.size())*2);

          for (int i{}; i < nums.size(); ++i) {
                ans[i] = ans[i + nums.size()] = nums[i];
          }
        return ans;
    }
};