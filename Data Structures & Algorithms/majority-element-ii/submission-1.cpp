class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        int n {static_cast<int>(nums.size())};
        std::vector<int> res;

        // count frequencies by value and put it in the hashmap
        for (int num : nums) {
            freq[num]++;
        }

        for (auto pairs : freq) {
            if (pairs.second > n/3) {
                res.push_back(pairs.first);
            }
        }
        return res;
    }
};