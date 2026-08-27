class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());
        int longest{};

        // If a number below dont exist, means it must be the start of a sequence
        for (int num : numbers) {
            if (numbers.find(num - 1) == numbers.end()) {
                int length{1};
                while(numbers.find(num + length) != numbers.end()) {
                    length++;
                }

                longest = std::max(longest, length);
            }
        }
        return longest;
    }
};