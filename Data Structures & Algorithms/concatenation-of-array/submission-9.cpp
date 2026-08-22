class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> ans{};
        for (int i{}; i < 2; ++i) {
            for (int num : nums) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};