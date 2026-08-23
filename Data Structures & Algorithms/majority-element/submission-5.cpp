class Solution {
public:
    int majorityElement(vector<int>& nums) {
            int n{ static_cast<int>(nums.size())};

            for (int num : nums) {
                if (std::count(nums.begin(), nums.end(), num) > n/2) {
                    return num;
                }
            }

            return -1;
        }
    };