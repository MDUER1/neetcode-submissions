class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        std::vector<vector<int>> freq(nums.size() + 1); // Add 1 cuz array of 5 has indices 0 to 4

        //Count frequency
        for (const int& num : nums ) {
            count[num]++; // Count the frequency of the given number
        }

        // Create the frequency buckets
        for (auto const& c : count) {
            freq[c.second].push_back(c.first); //index by frequency, values by the corresponding numbers
        }

        // create result array and push the k most frequent elements
        std::vector<int> result;
        for (int i = nums.size(); i > 0; i--) {
            for (int n : freq[i]) { // need to push each number with that frequency
                result.push_back(n); 
                if (result.size() == k) {
                return result;
            }
            }
        }
        return result;
    }
};
